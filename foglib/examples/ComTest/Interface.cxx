#ifndef INTERFACE_CXX
#define INTERFACE_CXX

#include <new>

#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif

namespace Interface
{
#line 252 "../../src/Com/Interface.fog"
    Text::String GetValueTreeString(const Value& v, Text::String key, int indent)
    {
#line 253
        static thread_local Container::Index < void * > visited;
        if (!indent)
            visited.Clear();
#line 257
        Text::String s;
        for (int i = 0; i < indent; i ++ )
            s.Cat('\t');
        s << key;
#line 262
        void * obj = v.GetObject();
        if (obj)
        {
#line 264
            if (visited.Find(obj) >= 0)
                return s + ": <recursive>\n";
            visited.Add(obj);
        }
#line 269
        if (v.IsMap())
        {
#line 270
            s.Cat('\n');
            const ValueMap & map = v.Get < ValueMap > ();
            for (int i = 0; i < map.GetCount(); i ++ )
                {
#line 273
                    Text::String key = map.GetKey(i);
                    const Value & v0 = map[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else 
#line 278
        if (v.IsArray())
        {
#line 279
            s.Cat('\n');
            const ValueArray & arr = v.Get < ValueArray > ();
            for (int i = 0; i < arr.GetCount(); i ++ )
                {
#line 282
                    Text::String key = Text::String::IntStr(i);
                    const Value & v0 = arr[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else 
#line 287
        if (v.IsArrayMapComb())
        {
#line 288
            s.Cat('\n');
            const ValueArrayMapComb & comb = v.Get < ValueArrayMapComb > ();
            for (int i = 0; i < comb.map.GetCount(); i ++ )
                {
#line 291
                    Text::String key = comb.map.GetKey(i);
                    const Value & v0 = comb.map[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
            for (int i = 0; i < comb.arr.GetCount(); i ++ )
                {
#line 296
                    Text::String key = Text::String::IntStr(i);
                    const Value & v0 = comb.arr[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else
        {
#line 302
            s << ": " << v.AsString() << "\n";
        }
#line 305
        if (obj)
            visited.RemoveLast();
#line 308
        return s;
    };
    
#line 325
    Formater& Formater::operator()(Text::String s)
    {
#line 325
        values.Add().Create1 < Text::String > (s);
#line 325
        return *this;
    };
    
#line 324
    Formater& Formater::operator()(int i)
    {
#line 324
        values.Add().Create1 < int > (i);
#line 324
        return *this;
    };
    
#line 326
    Formater::operator Text::String()
    {
#line 327
        if (pattern.IsEmpty())
#line 327
            return "";
#line 329
        int arg = 0;
        Text::String out;
        const char * it = pattern.Begin();
        const char * end = pattern.End();
        while (it != end)
            {
#line 334
                int chr = *it ++ ;
#line 337
                if (chr == 92 && *it == 37)
                {
#line 338
                    chr = *it ++ ;
                    out.Cat(chr);
                }
                else 
                if (chr == 37)
                {
#line 343
                    int state = FMT_MAIN_SWITCH;
                    int type = FMT_TYPE_INVALID;
                    while (it != end)
                        {
#line 346
                            chr = *it ++ ;
                            if (state == FMT_MAIN_SWITCH)
                            {
#line 348
                                if (chr == 'v')
                                {
#line 349
                                    type = FMT_TYPE_VALUE;
                                    break;
                                
                                }
                                else
#line 352
                                    break;
                            
                            }
                            else
#line 354
                                break;
                        
                        }
#line 356
                    if (type == FMT_TYPE_INVALID)
                        out << "<invalid>";
                    else 
#line 358
                    if (type == FMT_TYPE_VALUE)
                    {
#line 359
                        if (arg < values.GetCount())
                            out << values[arg ++ ].AsString();
                        else
                            out << "<arg overflow " << arg ++ << ">";
                    }
                }
                else
                {
#line 366
                    out.Cat(chr);
                }
            }
        return out;
    };
    
#line 93
    Value::Value(const char *str)
    {
#line 93
        Text::String & s = Create < Text::String > ();
#line 93
        s = str;
    };
    
#line 139
    Value *Value::AddMapSub(Text::String key, Value *def)
    {
#line 486
        if (IsMap() || IsArrayMapComb())
        {
#line 487
            ValueMap * map;
            if (IsMap())
#line 488
                map = &Get < ValueMap > ();
            else
#line 489
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return 0;
            else 
#line 493
            if (def)
                return&map -> Add(key, *def);
            else
                return&map -> Add(key);
        }
        else
#line 498
            return 0;
    };
    
#line 394
    ValueArray& Value::CreateArray()
    {
#line 395
        Create < ValueArray > ();
        return GetArray();
    };
    
#line 389
    ValueMap& Value::CreateMap()
    {
#line 390
        Create < ValueMap > ();
        return GetMap();
    };
    
#line 517
    void Value::DeepCopyArrayMap(Value v)
    {
#line 518
        if (v.IsArray())
            CreateArray().DeepCopyArrayMap(v.GetArray());
        else 
#line 520
        if (v.IsMap())
            CreateMap().DeepCopyArrayMap(v.GetMap());
        else
#line 522
            *this = v;
    };
    
#line 140
    Value *Value::GetAddMapSub(Text::String key, Value *def)
    {
#line 502
        if (IsMap() || IsArrayMapComb())
        {
#line 503
            ValueMap * map;
            if (IsMap())
#line 504
                map = &Get < ValueMap > ();
            else
#line 505
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return&map -> At(i);
            else 
#line 509
            if (def)
                return&map -> Add(key, *def);
            else
                return&map -> Add(key);
        }
        else
#line 514
            return 0;
    };
    
#line 465
    ValueArray& Value::GetArray()
    {
#line 466
        if (!Is < ValueArray > ())
            throw Text::Exc("Not a ValueArray");
        return Get < ValueArray > ();
    };
    
#line 453
    const ValueArray& Value::GetArray() const
    {
#line 454
        if (!Is < ValueArray > ())
            throw Text::Exc("Not a ValueArray");
        return Get < ValueArray > ();
    };
    
    ValueMap& Value::GetMap()
    {
#line 460
        if (!Is < ValueMap > ())
            throw Text::Exc("Not a ValueMap");
        return Get < ValueMap > ();
    };
    
#line 447
    const ValueMap& Value::GetMap() const
    {
#line 448
        if (!Is < ValueMap > ())
            throw Text::Exc("Not a ValueMap");
        return Get < ValueMap > ();
    };
    
#line 138
    Value *Value::GetMapSub(Text::String key, Value *def)
    {
#line 472
        if (IsMap() || IsArrayMapComb())
        {
#line 473
            ValueMap * map;
            if (IsMap())
#line 474
                map = &Get < ValueMap > ();
            else
#line 475
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return&map -> At(i);
            else
                return 0;
        }
        else
#line 482
            return 0;
    };
    
#line 399
    bool Value::IsArray() const
    {
#line 400
        return Is < ValueArray > ();
    };
    
#line 407
    bool Value::IsArrayMapComb() const
    {
#line 408
        return Is < ValueArrayMapComb > ();
    };
    
#line 148
    bool Value::IsInt() const
    {
#line 148
        return !obj.IsEmpty() && obj -> GetType() == INT_V;
    };
    
#line 149
    bool Value::IsInt64() const
    {
#line 149
        return !obj.IsEmpty() && obj -> GetType() == INT64_V;
    };
    
#line 403
    bool Value::IsMap() const
    {
#line 404
        return Is < ValueMap > ();
    };
    
#line 147
    bool Value::IsString() const
    {
#line 147
        return !obj.IsEmpty() && obj -> GetType() == STRING_V;
    };
    
#line 143
    bool Value::IsVoid() const
    {
#line 143
        if (obj)
#line 143
            return obj -> GetType() == VOID_V;
#line 143
        return true;
    };
    
#line 429
    ValueArray *Value::TryGetArray()
    {
#line 430
        if (IsArray())
            return&Get < ValueArray > ();
        else 
#line 432
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().arr;
        else
            return 0;
    };
    
#line 411
    const ValueArray *Value::TryGetArray() const
    {
#line 412
        if (IsArray())
            return&Get < ValueArray > ();
        else 
#line 414
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().arr;
        else
            return 0;
    };
    
#line 438
    ValueMap *Value::TryGetMap()
    {
#line 439
        if (IsMap())
            return&Get < ValueMap > ();
        else 
#line 441
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().map;
        else
            return 0;
    };
    
#line 420
    const ValueMap *Value::TryGetMap() const
    {
#line 421
        if (IsMap())
            return&Get < ValueMap > ();
        else 
#line 423
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().map;
        else
            return 0;
    };
    
#line 182
    Text::String ValueArray::AsString() const
    {
#line 182
        Text::String s;
#line 182
        s << "ValueArray(" << values.GetCount() << ")";
#line 182
        return s;
    };
    
#line 534
    void ValueArray::DeepCopyArrayMap(ValueArray& arr)
    {
#line 535
        Clear();
        SetCount(arr.GetCount());
        for (int i = 0; i < GetCount(); i ++ )
            {
#line 538
                Value & from = arr.At(i);
                Value & dst = At(i);
                dst.DeepCopyArrayMap(from);
            }
    };
    
#line 236
    void ValueArrayMapComb::operator= (const ValueArrayMapComb& v)
    {
#line 236
        arr = v.arr;
#line 236
        map = v.map;
    };
    
#line 241
    Text::String ValueArrayMapComb::AsString() const
    {
#line 241
        Text::String s;
#line 241
        s << "ValueArrayMapComb(" << arr.GetCount() << ", " << map.GetCount() << ")";
#line 241
        return s;
    };
    
#line 239
    void ValueArrayMapComb::Clear()
    {
#line 239
        arr.Clear();
#line 239
        map.Clear();
    };
    
#line 560
    void ValueArrayMapComb::DeepCopyArrayMap(ValueArrayMapComb& am)
    {
#line 561
        Clear();
        arr.SetCount(am.arr.GetCount());
        for (int i = 0; i < arr.GetCount(); i ++ )
            {
#line 564
                Value & from = am.arr.At(i);
                Value & dst = arr.At(i);
                dst.DeepCopyArrayMap(from);
            }
        for (int i = 0; i < am.map.GetCount(); i ++ )
            {
#line 569
                Text::String key = am.map.GetKey(i);
                Value & from = am.map.At(i);
                Value & dst = map.Add(key);
                dst.DeepCopyArrayMap(from);
            }
    };
    
#line 240
    int ValueArrayMapComb::GetTotal() const
    {
#line 240
        return arr.GetCount() + map.GetCount();
    };
    
#line 202
    void ValueMap::operator= (const ValueMap& m)
    {
#line 202
        keys <<= m.keys;
#line 202
        values <<= m.values;
    };
    
    Value& ValueMap::Add(Text::String key)
    {
#line 205
        keys.Add(key);
#line 205
        return values.Add();
    };
    
#line 204
    Value& ValueMap::Add(Text::String key, Value v)
    {
#line 204
        keys.Add(key);
#line 204
        return values.Add(v);
    };
    
#line 224
    Text::String ValueMap::AsString() const
    {
#line 224
        Text::String s;
#line 224
        s << "ValueMap(" << keys.GetCount() << ")";
#line 224
        return s;
    };
    
#line 215
    void ValueMap::Clear()
    {
#line 215
        keys.Clear();
#line 215
        values.Clear();
    };
    
#line 547
    void ValueMap::DeepCopyArrayMap(ValueMap& map)
    {
#line 548
        Clear();
        for (int i = 0; i < map.GetCount(); i ++ )
            {
#line 550
                Text::String key = map.GetKey(i);
                Value & from = map.At(i);
                Value & dst = Add(key);
                dst.DeepCopyArrayMap(from);
            }
    };
    
#line 211
    int ValueMap::Find(Text::String key) const
    {
#line 211
        for (int i = 0; i < keys.GetCount(); i ++ )
#line 211
            if (keys[i] == key)
#line 211
                return i;
#line 211
        return - 1;
    };
    
#line 212
    Value& ValueMap::Get(Text::String key)
    {
#line 212
        int i = Find(key);
#line 212
        if (i == - 1)
#line 212
            throw Text::Exc("Unexpected key");
#line 212
        return values[i];
    };
    
#line 207
    Value& ValueMap::GetAdd(Text::String key)
    {
#line 207
        int i = Find(key);
#line 207
        if (i >= 0)
#line 207
            return values[i];
#line 207
        return Add(key);
    };
    
#line 208
    Value& ValueMap::GetAdd(Text::String key, const Value& def)
    {
#line 208
        int i = Find(key);
#line 208
        if (i >= 0)
#line 208
            return values[i];
#line 208
        return Add(key, def);
    };
    
#line 213
    int ValueMap::GetPos(Value *v) const
    {
#line 213
        for (int i = 0; i < values.GetCount(); i ++ )
#line 213
            if (&values[i] == v)
#line 213
                return i;
#line 213
        return - 1;
    };
    
#line 210
    Value *ValueMap::TryFind(Text::String key)
    {
#line 210
        int i = Find(key);
#line 210
        if (i >= 0)
#line 210
            return&At(i);
#line 210
        return 0;
    };
    
#line 209
    Value ValueMap::TryGet(Text::String key, Value def)
    {
#line 209
        int i = Find(key);
#line 209
        if (i >= 0)
#line 209
            return At(i);
        else
#line 209
            return def;
    };
    
#line 61
    ValueObject::~ValueObject() {};
    
#line 64
    Lang::int64 ValueObject::AsInt() const
    {
#line 64
        return 0;
    };
    
#line 63
    Text::String ValueObject::AsString() const
    {
#line 63
        return "VOID";
    };
    
#line 62
    void *ValueObject::Get()
    {
#line 62
        return 0;
    };
    
};

#endif
