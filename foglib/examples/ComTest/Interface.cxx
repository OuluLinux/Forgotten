#ifndef INTERFACE_CXX
#define INTERFACE_CXX

#include <new>

#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif

namespace Interface
{
#line 318 "../../src/Com/Interface.fog"
    Text::String Format(Text::String pattern, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
#line 319
        static const int MAX_ARGS = 8;
        Value * v[MAX_ARGS] = 
        {
            &v0,
            &v1,
            &v2,
            &v3,
            &v4,
            &v5,
            &v6,
            &v7
        };
#line 322
        if (pattern.IsEmpty())
#line 322
            return "";
#line 324
        int arg = 0;
        Text::String out;
        const char * it = pattern.Begin();
        const char * end = pattern.End();
        while (it != end)
            {
#line 329
                int chr = *it ++ ;
#line 332
                if (chr == 92 && *it == 37)
                {
#line 333
                    chr = *it ++ ;
                    out.Cat(chr);
                }
                else 
                if (chr == 37)
                {
#line 338
                    int state = FMT_MAIN_SWITCH;
                    int type = FMT_TYPE_INVALID;
                    while (it != end)
                        {
#line 341
                            chr = *it ++ ;
                            if (state == FMT_MAIN_SWITCH)
                            {
#line 343
                                if (chr == 'v')
                                {
#line 344
                                    type = FMT_TYPE_VALUE;
                                    break;
                                
                                }
                                else
#line 347
                                    break;
                            
                            }
                            else
#line 349
                                break;
                        
                        }
#line 351
                    if (type == FMT_TYPE_INVALID)
                        out << "<invalid>";
                    else 
#line 353
                    if (type == FMT_TYPE_VALUE)
                    {
#line 354
                        if (arg < MAX_ARGS)
                            out << v[arg ++ ] -> AsString();
                        else
                            out << "<arg overflow " << arg ++ << ">";
                    }
                }
                else
                {
#line 361
                    out.Cat(chr);
                }
            }
        return out;
    };
    
#line 252
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
#line 480
        if (IsMap() || IsArrayMapComb())
        {
#line 481
            ValueMap * map;
            if (IsMap())
#line 482
                map = &Get < ValueMap > ();
            else
#line 483
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return 0;
            else 
#line 487
            if (def)
                return&map -> Add(key, *def);
            else
                return&map -> Add(key);
        }
        else
#line 492
            return 0;
    };
    
#line 388
    ValueArray& Value::CreateArray()
    {
#line 389
        Create < ValueArray > ();
        return GetArray();
    };
    
#line 383
    ValueMap& Value::CreateMap()
    {
#line 384
        Create < ValueMap > ();
        return GetMap();
    };
    
#line 511
    void Value::DeepCopyArrayMap(Value v)
    {
#line 512
        if (v.IsArray())
            CreateArray().DeepCopyArrayMap(v.GetArray());
        else 
#line 514
        if (v.IsMap())
            CreateMap().DeepCopyArrayMap(v.GetMap());
        else
#line 516
            *this = v;
    };
    
#line 140
    Value *Value::GetAddMapSub(Text::String key, Value *def)
    {
#line 496
        if (IsMap() || IsArrayMapComb())
        {
#line 497
            ValueMap * map;
            if (IsMap())
#line 498
                map = &Get < ValueMap > ();
            else
#line 499
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return&map -> At(i);
            else 
#line 503
            if (def)
                return&map -> Add(key, *def);
            else
                return&map -> Add(key);
        }
        else
#line 508
            return 0;
    };
    
#line 459
    ValueArray& Value::GetArray()
    {
#line 460
        if (!Is < ValueArray > ())
            throw Text::Exc("Not a ValueArray");
        return Get < ValueArray > ();
    };
    
#line 447
    const ValueArray& Value::GetArray() const
    {
#line 448
        if (!Is < ValueArray > ())
            throw Text::Exc("Not a ValueArray");
        return Get < ValueArray > ();
    };
    
    ValueMap& Value::GetMap()
    {
#line 454
        if (!Is < ValueMap > ())
            throw Text::Exc("Not a ValueMap");
        return Get < ValueMap > ();
    };
    
#line 441
    const ValueMap& Value::GetMap() const
    {
#line 442
        if (!Is < ValueMap > ())
            throw Text::Exc("Not a ValueMap");
        return Get < ValueMap > ();
    };
    
#line 138
    Value *Value::GetMapSub(Text::String key, Value *def)
    {
#line 466
        if (IsMap() || IsArrayMapComb())
        {
#line 467
            ValueMap * map;
            if (IsMap())
#line 468
                map = &Get < ValueMap > ();
            else
#line 469
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return&map -> At(i);
            else
                return 0;
        }
        else
#line 476
            return 0;
    };
    
#line 393
    bool Value::IsArray() const
    {
#line 394
        return Is < ValueArray > ();
    };
    
#line 401
    bool Value::IsArrayMapComb() const
    {
#line 402
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
    
#line 397
    bool Value::IsMap() const
    {
#line 398
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
    
#line 423
    ValueArray *Value::TryGetArray()
    {
#line 424
        if (IsArray())
            return&Get < ValueArray > ();
        else 
#line 426
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().arr;
        else
            return 0;
    };
    
#line 405
    const ValueArray *Value::TryGetArray() const
    {
#line 406
        if (IsArray())
            return&Get < ValueArray > ();
        else 
#line 408
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().arr;
        else
            return 0;
    };
    
#line 432
    ValueMap *Value::TryGetMap()
    {
#line 433
        if (IsMap())
            return&Get < ValueMap > ();
        else 
#line 435
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().map;
        else
            return 0;
    };
    
#line 414
    const ValueMap *Value::TryGetMap() const
    {
#line 415
        if (IsMap())
            return&Get < ValueMap > ();
        else 
#line 417
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
    
#line 528
    void ValueArray::DeepCopyArrayMap(ValueArray& arr)
    {
#line 529
        Clear();
        SetCount(arr.GetCount());
        for (int i = 0; i < GetCount(); i ++ )
            {
#line 532
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
    
#line 554
    void ValueArrayMapComb::DeepCopyArrayMap(ValueArrayMapComb& am)
    {
#line 555
        Clear();
        arr.SetCount(am.arr.GetCount());
        for (int i = 0; i < arr.GetCount(); i ++ )
            {
#line 558
                Value & from = am.arr.At(i);
                Value & dst = arr.At(i);
                dst.DeepCopyArrayMap(from);
            }
        for (int i = 0; i < am.map.GetCount(); i ++ )
            {
#line 563
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
    
#line 541
    void ValueMap::DeepCopyArrayMap(ValueMap& map)
    {
#line 542
        Clear();
        for (int i = 0; i < map.GetCount(); i ++ )
            {
#line 544
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
