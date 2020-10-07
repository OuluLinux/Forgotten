#ifndef INTERFACE_CXX
#define INTERFACE_CXX

#include <new>

#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif

namespace Interface
{
#line 253 "../../src/Com/Interface.fog"
    Text::String GetValueTreeString(const Value& v, Text::String key, int indent)
    {
#line 254
        static thread_local Container::Index < void * > visited;
        if (!indent)
            visited.Clear();
#line 258
        Text::String s;
        for (int i = 0; i < indent; i ++ )
            s.Cat('\t');
        s << key;
#line 263
        void * obj = v.GetObject();
        if (obj)
        {
#line 265
            if (visited.Find(obj) >= 0)
                return s + ": <recursive>\n";
            visited.Add(obj);
        }
#line 270
        if (v.IsMap())
        {
#line 271
            s.Cat('\n');
            const ValueMap & map = v.Get < ValueMap > ();
            for (int i = 0; i < map.GetCount(); i ++ )
                {
#line 274
                    Text::String key = map.GetKey(i);
                    const Value & v0 = map[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else 
#line 279
        if (v.IsArray())
        {
#line 280
            s.Cat('\n');
            const ValueArray & arr = v.Get < ValueArray > ();
            for (int i = 0; i < arr.GetCount(); i ++ )
                {
#line 283
                    Text::String key = Text::String::IntStr(i);
                    const Value & v0 = arr[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else 
#line 288
        if (v.IsArrayMapComb())
        {
#line 289
            s.Cat('\n');
            const ValueArrayMapComb & comb = v.Get < ValueArrayMapComb > ();
            for (int i = 0; i < comb.map.GetCount(); i ++ )
                {
#line 292
                    Text::String key = comb.map.GetKey(i);
                    const Value & v0 = comb.map[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
            for (int i = 0; i < comb.arr.GetCount(); i ++ )
                {
#line 297
                    Text::String key = Text::String::IntStr(i);
                    const Value & v0 = comb.arr[i];
                    s << GetValueTreeString(v0, key, indent + 1);
                }
        }
        else
        {
#line 303
            s << ": " << v.AsString() << "\n";
        }
#line 306
        if (obj)
            visited.RemoveLast();
#line 309
        return s;
    };
    
#line 631
    Convert::Convert() {};
    
#line 601
    Convert::~Convert() {};
    
#line 605
    int Convert::Filter(int chr) const
    {
#line 661
        return chr;
    };
    
#line 603
    Value Convert::Format(const Value& q) const
    {
#line 635
        if (q.IsVoid())
            return AsValue(Text::String());
        switch (q.GetType())
        {
#line 638
            case INT64_V:
                return AsValue(Text::String::IntStr64((Lang::int64) q));
            case INT_V:
                case BOOL_V:
                    return AsValue(Text::String::IntStr((int) q));
            case DOUBLE_V:
                return AsValue(Text::String::DblStr((double) q));
            case DATE_V:
                return AsValue(q.ForcedGet < Chrono::Date > ().AsString());
            case TIME_V:
                return AsValue(q.ForcedGet < Chrono::Time > ().AsString());
            case STRING_V:
                case WSTRING_V:
                    return q;
        }
        return AsValue(q.AsString());
    };
    
#line 604
    Value Convert::Scan(const Value& text) const
    {
#line 657
        return text;
    };
    
#line 327
    Formater& Formater::operator()(Text::String s)
    {
#line 327
        values.Add().Create1 < Text::String > (s);
#line 327
        return *this;
    };
    
#line 326
    Formater& Formater::operator()(int i)
    {
#line 326
        values.Add().Create1 < int > (i);
#line 326
        return *this;
    };
    
#line 328
    Formater::operator Text::String()
    {
#line 329
        if (pattern.IsEmpty())
#line 329
            return "";
#line 331
        int arg = 0;
        Text::String out;
        const char * it = pattern.Begin();
        const char * end = pattern.End();
        while (it != end)
            {
#line 336
                int chr = *it ++ ;
#line 339
                if (chr == 92 && *it == 37)
                {
#line 340
                    chr = *it ++ ;
                    out.Cat(chr);
                }
                else 
                if (chr == 37)
                {
#line 345
                    int state = FMT_MAIN_SWITCH;
                    int type = FMT_TYPE_INVALID;
                    while (it != end)
                        {
#line 348
                            chr = *it ++ ;
                            if (state == FMT_MAIN_SWITCH)
                            {
#line 350
                                if (chr == 's')
                                {
#line 351
                                    type = FMT_TYPE_STRING;
                                    break;
                                
                                }
                                else 
#line 354
                                if (chr == 'd')
                                {
#line 355
                                    type = FMT_TYPE_INT;
                                    break;
                                
                                }
                                else
#line 358
                                    break;
                            
                            }
                            else
#line 360
                                break;
                        
                        }
#line 362
                    if (type == FMT_TYPE_INVALID)
                        out << "<invalid>";
                    else 
#line 364
                    if (type == FMT_TYPE_STRING)
                    {
#line 365
                        if (arg < values.GetCount())
                            out << values[arg ++ ].AsString();
                        else
                            out << "<arg overflow " << arg ++ << ">";
                    }
                    else 
#line 370
                    if (type == FMT_TYPE_INT)
                    {
#line 371
                        if (arg < values.GetCount())
                            out << Text::String::IntStr(values[arg ++ ].AsInt());
                        else
                            out << "<arg overflow " << arg ++ << ">";
                    }
                }
                else
                {
#line 378
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
    
#line 140
    Value *Value::AddMapSub(Text::String key, Value *def)
    {
#line 498
        if (IsMap() || IsArrayMapComb())
        {
#line 499
            ValueMap * map;
            if (IsMap())
#line 500
                map = &Get < ValueMap > ();
            else
#line 501
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return 0;
            else 
#line 505
            if (def)
                return&map -> Add(key, *def);
            else
                return&map -> Add(key);
        }
        else
#line 510
            return 0;
    };
    
#line 406
    ValueArray& Value::CreateArray()
    {
#line 407
        Create < ValueArray > ();
        return GetArray();
    };
    
#line 401
    ValueMap& Value::CreateMap()
    {
#line 402
        Create < ValueMap > ();
        return GetMap();
    };
    
#line 529
    void Value::DeepCopyArrayMap(Value v)
    {
#line 530
        if (v.IsArray())
            CreateArray().DeepCopyArrayMap(v.GetArray());
        else 
#line 532
        if (v.IsMap())
            CreateMap().DeepCopyArrayMap(v.GetMap());
        else
#line 534
            *this = v;
    };
    
#line 141
    Value *Value::GetAddMapSub(Text::String key, Value *def)
    {
#line 514
        if (IsMap() || IsArrayMapComb())
        {
#line 515
            ValueMap * map;
            if (IsMap())
#line 516
                map = &Get < ValueMap > ();
            else
#line 517
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return&map -> At(i);
            else 
#line 521
            if (def)
                return&map -> Add(key, *def);
            else
                return&map -> Add(key);
        }
        else
#line 526
            return 0;
    };
    
#line 477
    ValueArray& Value::GetArray()
    {
#line 478
        if (!Is < ValueArray > ())
            throw Text::Exc("Not a ValueArray");
        return Get < ValueArray > ();
    };
    
#line 465
    const ValueArray& Value::GetArray() const
    {
#line 466
        if (!Is < ValueArray > ())
            throw Text::Exc("Not a ValueArray");
        return Get < ValueArray > ();
    };
    
    ValueMap& Value::GetMap()
    {
#line 472
        if (!Is < ValueMap > ())
            throw Text::Exc("Not a ValueMap");
        return Get < ValueMap > ();
    };
    
#line 459
    const ValueMap& Value::GetMap() const
    {
#line 460
        if (!Is < ValueMap > ())
            throw Text::Exc("Not a ValueMap");
        return Get < ValueMap > ();
    };
    
#line 139
    Value *Value::GetMapSub(Text::String key, Value *def)
    {
#line 484
        if (IsMap() || IsArrayMapComb())
        {
#line 485
            ValueMap * map;
            if (IsMap())
#line 486
                map = &Get < ValueMap > ();
            else
#line 487
                map = &Get < ValueArrayMapComb > ().map;
            int i = map -> Find(key);
            if (i >= 0)
                return&map -> At(i);
            else
                return 0;
        }
        else
#line 494
            return 0;
    };
    
#line 411
    bool Value::IsArray() const
    {
#line 412
        return Is < ValueArray > ();
    };
    
#line 419
    bool Value::IsArrayMapComb() const
    {
#line 420
        return Is < ValueArrayMapComb > ();
    };
    
#line 149
    bool Value::IsInt() const
    {
#line 149
        return !obj.IsEmpty() && obj -> GetType() == INT_V;
    };
    
#line 150
    bool Value::IsInt64() const
    {
#line 150
        return !obj.IsEmpty() && obj -> GetType() == INT64_V;
    };
    
#line 415
    bool Value::IsMap() const
    {
#line 416
        return Is < ValueMap > ();
    };
    
#line 148
    bool Value::IsString() const
    {
#line 148
        return !obj.IsEmpty() && obj -> GetType() == STRING_V;
    };
    
#line 144
    bool Value::IsVoid() const
    {
#line 144
        if (obj)
#line 144
            return obj -> GetType() == VOID_V;
#line 144
        return true;
    };
    
#line 441
    ValueArray *Value::TryGetArray()
    {
#line 442
        if (IsArray())
            return&Get < ValueArray > ();
        else 
#line 444
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().arr;
        else
            return 0;
    };
    
#line 423
    const ValueArray *Value::TryGetArray() const
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
    
#line 450
    ValueMap *Value::TryGetMap()
    {
#line 451
        if (IsMap())
            return&Get < ValueMap > ();
        else 
#line 453
        if (IsArrayMapComb())
            return&Get < ValueArrayMapComb > ().map;
        else
            return 0;
    };
    
#line 432
    const ValueMap *Value::TryGetMap() const
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
    
#line 183
    Text::String ValueArray::AsString() const
    {
#line 183
        Text::String s;
#line 183
        s << "ValueArray(" << values.GetCount() << ")";
#line 183
        return s;
    };
    
#line 546
    void ValueArray::DeepCopyArrayMap(ValueArray& arr)
    {
#line 547
        Clear();
        SetCount(arr.GetCount());
        for (int i = 0; i < GetCount(); i ++ )
            {
#line 550
                Value & from = arr.At(i);
                Value & dst = At(i);
                dst.DeepCopyArrayMap(from);
            }
    };
    
#line 237
    void ValueArrayMapComb::operator= (const ValueArrayMapComb& v)
    {
#line 237
        arr = v.arr;
#line 237
        map = v.map;
    };
    
#line 242
    Text::String ValueArrayMapComb::AsString() const
    {
#line 242
        Text::String s;
#line 242
        s << "ValueArrayMapComb(" << arr.GetCount() << ", " << map.GetCount() << ")";
#line 242
        return s;
    };
    
#line 240
    void ValueArrayMapComb::Clear()
    {
#line 240
        arr.Clear();
#line 240
        map.Clear();
    };
    
#line 572
    void ValueArrayMapComb::DeepCopyArrayMap(ValueArrayMapComb& am)
    {
#line 573
        Clear();
        arr.SetCount(am.arr.GetCount());
        for (int i = 0; i < arr.GetCount(); i ++ )
            {
#line 576
                Value & from = am.arr.At(i);
                Value & dst = arr.At(i);
                dst.DeepCopyArrayMap(from);
            }
        for (int i = 0; i < am.map.GetCount(); i ++ )
            {
#line 581
                Text::String key = am.map.GetKey(i);
                Value & from = am.map.At(i);
                Value & dst = map.Add(key);
                dst.DeepCopyArrayMap(from);
            }
    };
    
#line 241
    int ValueArrayMapComb::GetTotal() const
    {
#line 241
        return arr.GetCount() + map.GetCount();
    };
    
#line 203
    void ValueMap::operator= (const ValueMap& m)
    {
#line 203
        keys <<= m.keys;
#line 203
        values <<= m.values;
    };
    
    Value& ValueMap::Add(Text::String key)
    {
#line 206
        keys.Add(key);
#line 206
        return values.Add();
    };
    
#line 205
    Value& ValueMap::Add(Text::String key, Value v)
    {
#line 205
        keys.Add(key);
#line 205
        return values.Add(v);
    };
    
#line 225
    Text::String ValueMap::AsString() const
    {
#line 225
        Text::String s;
#line 225
        s << "ValueMap(" << keys.GetCount() << ")";
#line 225
        return s;
    };
    
#line 216
    void ValueMap::Clear()
    {
#line 216
        keys.Clear();
#line 216
        values.Clear();
    };
    
#line 559
    void ValueMap::DeepCopyArrayMap(ValueMap& map)
    {
#line 560
        Clear();
        for (int i = 0; i < map.GetCount(); i ++ )
            {
#line 562
                Text::String key = map.GetKey(i);
                Value & from = map.At(i);
                Value & dst = Add(key);
                dst.DeepCopyArrayMap(from);
            }
    };
    
#line 212
    int ValueMap::Find(Text::String key) const
    {
#line 212
        for (int i = 0; i < keys.GetCount(); i ++ )
#line 212
            if (keys[i] == key)
#line 212
                return i;
#line 212
        return - 1;
    };
    
#line 213
    Value& ValueMap::Get(Text::String key)
    {
#line 213
        int i = Find(key);
#line 213
        if (i == - 1)
#line 213
            throw Text::Exc("Unexpected key");
#line 213
        return values[i];
    };
    
#line 208
    Value& ValueMap::GetAdd(Text::String key)
    {
#line 208
        int i = Find(key);
#line 208
        if (i >= 0)
#line 208
            return values[i];
#line 208
        return Add(key);
    };
    
#line 209
    Value& ValueMap::GetAdd(Text::String key, const Value& def)
    {
#line 209
        int i = Find(key);
#line 209
        if (i >= 0)
#line 209
            return values[i];
#line 209
        return Add(key, def);
    };
    
#line 214
    int ValueMap::GetPos(Value *v) const
    {
#line 214
        for (int i = 0; i < values.GetCount(); i ++ )
#line 214
            if (&values[i] == v)
#line 214
                return i;
#line 214
        return - 1;
    };
    
#line 211
    Value *ValueMap::TryFind(Text::String key)
    {
#line 211
        int i = Find(key);
#line 211
        if (i >= 0)
#line 211
            return&At(i);
#line 211
        return 0;
    };
    
#line 210
    Value ValueMap::TryGet(Text::String key, Value def)
    {
#line 210
        int i = Find(key);
#line 210
        if (i >= 0)
#line 210
            return At(i);
        else
#line 210
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
