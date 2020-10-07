#ifndef INTERFACE_HXX
#define INTERFACE_HXX

#include <new>

#ifndef CHRONO_HXX
#include <Chrono.hxx>
#endif
#ifndef NETWORK_HXX
#include <Network.hxx>
#endif

#ifndef SHARED_HXX
#include <Shared.hxx>
#endif

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Interface
{
    enum _anon_17
    {
        VOID_V = 0,
        INT_V = 1,
        DOUBLE_V = 2,
        STRING_V = 3,
        DATE_V = 4,
        TIME_V = 5,
        ERROR_V = 6,
        VALUE_V = 7,
        WSTRING_V = 8,
        VALUEARRAY_V = 9,
        INT64_V = 10,
        BOOL_V = 11,
        VALUEMAP_V = 12,
        VALUE_ARRAY_AND_MAP_V = 13,
        UNKNOWN_V = 0Xffffffff
    };
    enum _anon_18
    {
        FMT_MAIN_SWITCH = 0,
        FMT_TYPE_INVALID = 0,
        FMT_TYPE_STRING,
        FMT_TYPE_INT
    };
};

namespace Interface {
class Value;
}

namespace Interface
{
#line 156 "../../src/Com/Interface.fog"
    template < class _1 >
    inline Value AsValue(const _1& o);
#line 253
    Text::String GetValueTreeString(const Value& v, Text::String key, int indent);
#line 9
    inline int RegisterTypeNo(const char *type);
#line 16
    template < class _1 >
    inline int StaticTypeNo(_1 *p);
};

namespace Interface {
class Convert;
}

namespace Interface
{
#line 610
    inline const Convert& StdConvert();
#line 615
    inline Text::String StdFormat(const Value& q);
#line 52
    inline Lang::dword ValueTypeNo(const Chrono::Date *);
    inline Lang::dword ValueTypeNo(const Chrono::Time *);
    inline Lang::dword ValueTypeNo(const Value *);
#line 47
    inline Lang::dword ValueTypeNo(const Lang::int64 *);
#line 50
    inline Lang::dword ValueTypeNo(const Text::String *);
    inline Lang::dword ValueTypeNo(const Text::WString *);
#line 42
    template < class _1 >
    inline Lang::dword ValueTypeNo(const _1 *);
#line 49
    inline Lang::dword ValueTypeNo(const bool *);
#line 48
    inline Lang::dword ValueTypeNo(const double *);
#line 46
    inline Lang::dword ValueTypeNo(const int *);
#line 45
    inline Lang::dword ValueTypeNo(const void *);
};

namespace Interface {
class ValueArray;
}

namespace Interface
{
#line 247
    template <>
    inline Lang::dword ValueTypeNo < ValueArray > (const ValueArray *);
};

namespace Interface {
struct ValueArrayMapComb;
}

namespace Interface
{
#line 249
    template <>
    inline Lang::dword ValueTypeNo < ValueArrayMapComb > (const ValueArrayMapComb *);
};

namespace Interface {
class ValueMap;
}

namespace Interface
{
#line 248
    template <>
    inline Lang::dword ValueTypeNo < ValueMap > (const ValueMap *);
    
    class Convert
    {
    public:
#line 631
        Convert();
#line 601
        virtual ~Convert();
#line 607
        inline Value operator()(const Value& q) const;
#line 605
        virtual int Filter(int chr) const;
#line 603
        virtual Value Format(const Value& q) const;
        virtual Value Scan(const Value& text) const;
    };
    
    struct Formater
    {
#line 321
        Text::String pattern;
        Container::Vector < Value > values;
        
        inline Formater(Text::String pattern);
        inline Formater& operator()(Value v);
#line 327
        Formater& operator()(Text::String s);
#line 326
        Formater& operator()(int i);
#line 328
        operator Text::String();
    };
};

namespace Interface {
class ValueObject;
}

namespace Interface
{
    class Value
    {
#line 87
        Shared::Ptr < ValueObject > obj;
        
    public:
#line 91
        inline Value();
        inline Value(const Value& v);
        Value(const char *str);
#line 106
        template < class _1 >
        inline Value& operator= (const Value& v);
#line 103
        inline bool operator== (const Value& v) const;
#line 120
        template < class _1 >
        inline operator _1 & () const;
#line 140
        Value *AddMapSub(Text::String key, Value *def = 0);
#line 153
        inline Lang::int64 AsInt() const;
#line 152
        inline Text::String AsString() const;
#line 110
        template < class _1 >
        inline void Attach(_1 *o);
#line 96
        inline void Clear();
        template < class _1 >
        inline _1& Create();
#line 98
        template < class _1 >
        inline _1& Create1(const _1& arg);
#line 406
        ValueArray& CreateArray();
#line 401
        ValueMap& CreateMap();
#line 529
        void DeepCopyArrayMap(Value v);
#line 130
        template < class _1 >
        inline _1& ForcedGet() const;
#line 125
        template < class _1 >
        inline _1& Get() const;
#line 141
        Value *GetAddMapSub(Text::String key, Value *def = 0);
#line 477
        ValueArray& GetArray();
#line 465
        const ValueArray& GetArray() const;
#line 471
        ValueMap& GetMap();
#line 459
        const ValueMap& GetMap() const;
#line 139
        Value *GetMapSub(Text::String key, Value *def = 0);
#line 142
        inline ValueObject *GetObject() const;
#line 105
        inline Lang::dword GetType() const;
#line 112
        template < class _1 >
        inline bool Is() const;
#line 411
        bool IsArray() const;
#line 419
        bool IsArrayMapComb() const;
#line 149
        bool IsInt() const;
        bool IsInt64() const;
#line 415
        bool IsMap() const;
#line 148
        bool IsString() const;
#line 144
        bool IsVoid() const;
#line 111
        template < class _1 >
        inline void Set(const _1& o);
        template < class _1 >
        inline _1 *Try() const;
#line 441
        ValueArray *TryGetArray();
#line 423
        const ValueArray *TryGetArray() const;
#line 450
        ValueMap *TryGetMap();
#line 432
        const ValueMap *TryGetMap() const;
    };
    
    class ValueArray
    {
#line 159
        typedef Container::Array < Value > A;
        
#line 160
        A values;
        
    public:
#line 164
        inline ValueArray();
        inline ValueArray(const ValueArray& m);
        inline void operator= (const ValueArray& m);
#line 175
        inline Value& operator[](int i);
#line 177
        inline const Value& operator[](int i) const;
#line 169
        inline Value& Add();
        inline Value& Add(const Value& v);
        template < class _1 >
        inline Value& AddAsValue(const _1& o);
#line 184
        inline Lang::int64 AsInt() const;
#line 183
        Text::String AsString() const;
#line 176
        inline Value& At(int i);
#line 178
        inline const Value& At(int i) const;
#line 168
        inline void Clear();
#line 546
        void DeepCopyArrayMap(ValueArray& arr);
#line 174
        inline int GetCount() const;
#line 172
        inline Value& Insert(int i);
        inline Value& Insert(int i, const Value& v);
#line 179
        inline bool IsEmpty() const;
        inline void SetCount(int i);
#line 188
        inline Lang::ConstFwdPtrIterator < Value > begin() const;
#line 186
        inline Lang::FwdPtrIterator < Value > begin();
#line 189
        inline Lang::ConstFwdPtrIterator < Value > end() const;
#line 187
        inline Lang::FwdPtrIterator < Value > end();
    };
    
    class ValueMap
    {
#line 196
        Container::Vector < Text::String > keys;
        Container::Array < Value > values;
        
    public:
#line 201
        inline ValueMap();
        inline ValueMap(const ValueMap& m);
        void operator= (const ValueMap& m);
#line 218
        inline Value& operator[](int i);
#line 220
        inline const Value& operator[](int i) const;
#line 206
        Value& Add(Text::String key);
#line 205
        Value& Add(Text::String key, Value v);
#line 207
        template < class _1 >
        inline Value& AddAsValue(Text::String key, const _1& o);
#line 226
        inline Lang::int64 AsInt() const;
#line 225
        Text::String AsString() const;
#line 219
        inline Value& At(int i);
#line 221
        inline const Value& At(int i) const;
#line 216
        void Clear();
#line 559
        void DeepCopyArrayMap(ValueMap& map);
#line 212
        int Find(Text::String key) const;
        Value& Get(Text::String key);
#line 208
        Value& GetAdd(Text::String key);
        Value& GetAdd(Text::String key, const Value& def);
#line 217
        inline int GetCount() const;
#line 222
        inline Text::String GetKey(int i) const;
#line 214
        int GetPos(Value *v) const;
#line 211
        Value *TryFind(Text::String key);
#line 210
        Value TryGet(Text::String key, Value def = Value());
    };
    
    struct ValueArrayMapComb
    {
#line 231
        ValueArray arr;
        ValueMap map;
        
#line 235
        inline ValueArrayMapComb();
        inline ValueArrayMapComb(const ValueArrayMapComb& v);
        void operator= (const ValueArrayMapComb& v);
#line 243
        inline Lang::int64 AsInt() const;
#line 242
        Text::String AsString() const;
#line 240
        void Clear();
#line 572
        void DeepCopyArrayMap(ValueArrayMapComb& am);
#line 241
        int GetTotal() const;
    };
    
    class ValueObject
    {
    protected:
#line 58
        Lang::dword type;
        
    public:
        virtual ~ValueObject();
#line 64
        virtual Lang::int64 AsInt() const;
#line 63
        virtual Text::String AsString() const;
#line 62
        virtual void *Get();
#line 65
        inline Lang::dword GetType() const;
    };
    
    template < class _1 >
    class ValueTemplate : public Interface::ValueObject
    {
#line 70
        bool is_owned;
        _1 *ptr;
        
    public:
        inline ValueTemplate();
        inline ValueTemplate(_1 *ptr);
        inline ValueTemplate(const _1& obj);
        inline ~ValueTemplate();
#line 80
        inline virtual Lang::int64 AsInt() const;
#line 79
        inline virtual Text::String AsString() const;
#line 78
        inline virtual void *Get();
    };
};

namespace Interface
{
#line 156
    template < class _1 >
    inline Value AsValue(const _1& o)
    {
#line 156
        Value v;
#line 156
        v.Create1 < _1 > (o);
#line 156
        return v;
    };
    
#line 9
    inline int RegisterTypeNo(const char *type)
    {
#line 10
        static Container::Index < Text::String > idx;
        return idx.FindAdd(type);
    };
    
#line 16
    template < class _1 >
    inline int StaticTypeNo(_1 *p)
    {
#line 18
        static int typeno = RegisterTypeNo(typeid(_1).name());
        return typeno;
    };
    
#line 610
    inline const Convert& StdConvert()
    {
#line 611
        static Convert h;
        return h;
    };
    
    inline Text::String StdFormat(const Value& q)
    {
#line 616
        return StdConvert().Format(q);
    };
    
#line 52
    inline Lang::dword ValueTypeNo(const Chrono::Date *)
    {
#line 52
        return DATE_V;
    };
    
#line 53
    inline Lang::dword ValueTypeNo(const Chrono::Time *)
    {
#line 53
        return TIME_V;
    };
    
#line 54
    inline Lang::dword ValueTypeNo(const Value *)
    {
#line 54
        return VALUE_V;
    };
    
#line 47
    inline Lang::dword ValueTypeNo(const Lang::int64 *)
    {
#line 47
        return INT64_V;
    };
    
    inline Lang::dword ValueTypeNo(const Text::String *)
    {
#line 50
        return STRING_V;
    };
    
#line 51
    inline Lang::dword ValueTypeNo(const Text::WString *)
    {
#line 51
        return WSTRING_V;
    };
    
#line 42
    template < class _1 >
    inline Lang::dword ValueTypeNo(const _1 *)
    {
#line 43
        return StaticTypeNo((_1 * )0) + 0x8000000;
    };
    
#line 49
    inline Lang::dword ValueTypeNo(const bool *)
    {
#line 49
        return BOOL_V;
    };
    
#line 48
    inline Lang::dword ValueTypeNo(const double *)
    {
#line 48
        return DOUBLE_V;
    };
    
#line 46
    inline Lang::dword ValueTypeNo(const int *)
    {
#line 46
        return INT_V;
    };
    
#line 45
    inline Lang::dword ValueTypeNo(const void *)
    {
#line 45
        return VOID_V;
    };
    
#line 247
    template <>
    inline Lang::dword ValueTypeNo < ValueArray > (const ValueArray *)
    {
#line 247
        return VALUEARRAY_V;
    };
    
#line 249
    template <>
    inline Lang::dword ValueTypeNo < ValueArrayMapComb > (const ValueArrayMapComb *)
    {
#line 249
        return VALUE_ARRAY_AND_MAP_V;
    };
    
#line 248
    template <>
    inline Lang::dword ValueTypeNo < ValueMap > (const ValueMap *)
    {
#line 248
        return VALUEMAP_V;
    };
    
#line 607
    inline Value Convert::operator()(const Value& q) const
    {
#line 607
        return Format(q);
    };
    
#line 324
    inline Formater::Formater(Text::String pattern)
    :
        pattern(pattern)
    {};
    
#line 325
    inline Formater& Formater::operator()(Value v)
    {
#line 325
        values.Add(v);
#line 325
        return *this;
    };
    
#line 91
    inline Value::Value() {};
    
#line 92
    inline Value::Value(const Value& v)
    {
#line 92
        *this = v;
    };
    
#line 106
    template < class _1 >
    inline Value& Value::operator= (const Value& v)
    {
#line 106
        obj = v.obj;
#line 106
        return *this;
    };
    
#line 103
    inline bool Value::operator== (const Value& v) const
    {
#line 103
        return obj == v.obj;
    };
    
#line 120
    template < class _1 >
    inline Value::operator _1 & () const
    {
#line 121
        if (obj && obj -> GetType() == ValueTypeNo < _1 > (0))
            return *(_1 * ) obj -> Get();
        throw Text::Exc("Unexpected value type");
    };
    
#line 153
    inline Lang::int64 Value::AsInt() const
    {
#line 153
        if (obj)
#line 153
            return obj -> AsInt();
#line 153
        return 0;
    };
    
#line 152
    inline Text::String Value::AsString() const
    {
#line 152
        if (obj)
#line 152
            return obj -> AsString();
#line 152
        return "NULL";
    };
    
#line 110
    template < class _1 >
    inline void Value::Attach(_1 *o)
    {
#line 110
        obj = new ValueTemplate < _1 > (o);
    };
    
#line 96
    inline void Value::Clear()
    {
#line 96
        obj.Clear();
    };
    
#line 97
    template < class _1 >
    inline _1& Value::Create()
    {
#line 97
        ValueTemplate < _1 > * o = new ValueTemplate < _1 > ;
#line 97
        _1 * t = (_1 * ) o -> Get();
#line 97
        obj.WrapObject(o);
#line 97
        return *t;
    };
    
#line 98
    template < class _1 >
    inline _1& Value::Create1(const _1& arg)
    {
#line 98
        ValueTemplate < _1 > * o = new ValueTemplate < _1 > (arg);
#line 98
        _1 * t = (_1 * ) o -> Get();
#line 98
        obj.WrapObject(o);
#line 98
        return *t;
    };
    
#line 130
    template < class _1 >
    inline _1& Value::ForcedGet() const
    {
#line 130
        return *(_1 * ) obj -> Get();
    };
    
#line 125
    template < class _1 >
    inline _1& Value::Get() const
    {
#line 126
        if (obj && obj -> GetType() == ValueTypeNo < _1 > (0))
            return *(_1 * ) obj -> Get();
        throw Text::Exc("Unexpected value type");
    };
    
#line 142
    inline ValueObject *Value::GetObject() const
    {
#line 142
        return obj.Get();
    };
    
#line 105
    inline Lang::dword Value::GetType() const
    {
#line 105
        if (obj)
#line 105
            return obj -> GetType();
#line 105
        return VOID_V;
    };
    
#line 112
    template < class _1 >
    inline bool Value::Is() const
    {
#line 112
        if (obj)
#line 112
            return obj -> GetType() == ValueTypeNo < _1 > (0);
#line 112
        return false;
    };
    
#line 111
    template < class _1 >
    inline void Value::Set(const _1& o)
    {
#line 111
        obj.WrapObject(new ValueTemplate < _1 > (o));
    };
    
#line 113
    template < class _1 >
    inline _1 *Value::Try() const
    {
#line 114
        if (obj && obj -> GetType() == ValueTypeNo < _1 > (0))
            return(_1 * ) obj -> Get();
        return 0;
    };
    
#line 164
    inline ValueArray::ValueArray() {};
    
#line 165
    inline ValueArray::ValueArray(const ValueArray& m)
    {
#line 165
        *this = m;
    };
    
#line 166
    inline void ValueArray::operator= (const ValueArray& m)
    {
#line 166
        values <<= m.values;
    };
    
#line 175
    inline Value& ValueArray::operator[](int i)
    {
#line 175
        return values[i];
    };
    
#line 177
    inline const Value& ValueArray::operator[](int i) const
    {
#line 177
        return values[i];
    };
    
#line 169
    inline Value& ValueArray::Add()
    {
#line 169
        return values.Add();
    };
    
#line 170
    inline Value& ValueArray::Add(const Value& v)
    {
#line 170
        return values.Add(v);
    };
    
#line 171
    template < class _1 >
    inline Value& ValueArray::AddAsValue(const _1& o)
    {
#line 171
        return values.Add(AsValue(o));
    };
    
#line 184
    inline Lang::int64 ValueArray::AsInt() const
    {
#line 184
        return values.GetCount();
    };
    
#line 176
    inline Value& ValueArray::At(int i)
    {
#line 176
        return values[i];
    };
    
#line 178
    inline const Value& ValueArray::At(int i) const
    {
#line 178
        return values[i];
    };
    
#line 168
    inline void ValueArray::Clear()
    {
#line 168
        values.Clear();
    };
    
#line 174
    inline int ValueArray::GetCount() const
    {
#line 174
        return values.GetCount();
    };
    
#line 172
    inline Value& ValueArray::Insert(int i)
    {
#line 172
        return values.Insert(i);
    };
    
#line 173
    inline Value& ValueArray::Insert(int i, const Value& v)
    {
#line 173
        return values.Insert(i, v);
    };
    
#line 179
    inline bool ValueArray::IsEmpty() const
    {
#line 179
        return values.IsEmpty();
    };
    
#line 180
    inline void ValueArray::SetCount(int i)
    {
#line 180
        values.SetCount(i);
    };
    
#line 188
    inline Lang::ConstFwdPtrIterator < Value > ValueArray::begin() const
    {
#line 188
        return values.begin();
    };
    
#line 186
    inline Lang::FwdPtrIterator < Value > ValueArray::begin()
    {
#line 186
        return values.begin();
    };
    
    inline Lang::ConstFwdPtrIterator < Value > ValueArray::end() const
    {
#line 189
        return values.end();
    };
    
#line 187
    inline Lang::FwdPtrIterator < Value > ValueArray::end()
    {
#line 187
        return values.end();
    };
    
#line 235
    inline ValueArrayMapComb::ValueArrayMapComb() {};
    
#line 236
    inline ValueArrayMapComb::ValueArrayMapComb(const ValueArrayMapComb& v)
    {
#line 236
        *this = v;
    };
    
#line 243
    inline Lang::int64 ValueArrayMapComb::AsInt() const
    {
#line 243
        return GetTotal();
    };
    
#line 201
    inline ValueMap::ValueMap() {};
    
#line 202
    inline ValueMap::ValueMap(const ValueMap& m)
    {
#line 202
        *this = m;
    };
    
#line 218
    inline Value& ValueMap::operator[](int i)
    {
#line 218
        return values[i];
    };
    
#line 220
    inline const Value& ValueMap::operator[](int i) const
    {
#line 220
        return values[i];
    };
    
#line 207
    template < class _1 >
    inline Value& ValueMap::AddAsValue(Text::String key, const _1& o)
    {
#line 207
        keys.Add(key);
#line 207
        return values.Add(AsValue(o));
    };
    
#line 226
    inline Lang::int64 ValueMap::AsInt() const
    {
#line 226
        return keys.GetCount();
    };
    
#line 219
    inline Value& ValueMap::At(int i)
    {
#line 219
        return values[i];
    };
    
#line 221
    inline const Value& ValueMap::At(int i) const
    {
#line 221
        return values[i];
    };
    
#line 217
    inline int ValueMap::GetCount() const
    {
#line 217
        return values.GetCount();
    };
    
#line 222
    inline Text::String ValueMap::GetKey(int i) const
    {
#line 222
        return keys[i];
    };
    
#line 65
    inline Lang::dword ValueObject::GetType() const
    {
#line 65
        return type;
    };
    
#line 74
    template < class _1 >
    inline ValueTemplate < _1 >::ValueTemplate()
    :
        is_owned(false),
        ptr(0)
    {
#line 74
        ptr = new _1;
#line 74
        is_owned = true;
#line 74
        type = ValueTypeNo < _1 > (0);
    };
    
#line 75
    template < class _1 >
    inline ValueTemplate < _1 >::ValueTemplate(_1 *ptr)
    :
        is_owned(false),
        ptr(ptr)
    {
#line 75
        type = ValueTypeNo < _1 > (0);
    };
    
#line 76
    template < class _1 >
    inline ValueTemplate < _1 >::ValueTemplate(const _1& obj)
    :
        is_owned(false),
        ptr(0)
    {
#line 76
        ptr = new _1(obj);
#line 76
        is_owned = true;
#line 76
        type = ValueTypeNo < _1 > (0);
    };
    
#line 77
    template < class _1 >
    inline ValueTemplate < _1 >::~ValueTemplate()
    {
#line 77
        if (is_owned && ptr)
        {
#line 77
            delete ptr;
#line 77
            ptr = 0;
#line 77
            is_owned = false;
#line 77
            type = VOID_V;
        }
    };
    
#line 80
    template < class _1 >
    inline Lang::int64 ValueTemplate < _1 >::AsInt() const
    {
#line 80
        if (ptr)
#line 80
            return Text::ToInt(*ptr);
#line 80
        return 0;
    };
    
#line 79
    template < class _1 >
    inline Text::String ValueTemplate < _1 >::AsString() const
    {
#line 79
        if (ptr)
#line 79
            return Text::ToString(*ptr);
#line 79
        return "NULL";
    };
    
#line 78
    template < class _1 >
    inline void *ValueTemplate < _1 >::Get()
    {
#line 78
        return ptr;
    };
    
};

#endif
