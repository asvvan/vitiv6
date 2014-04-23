//
// Generated file, do not edit! Created by opp_msgc 4.4 from hamnhamh1.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "hamnhamh1_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(HamnhamnMsg1);

HamnhamnMsg1::HamnhamnMsg1(const char *name, int kind) : ::cPacket(name,kind)
{
    this->source_var = 0;
    this->msg_var = 0;
    this->destination_var = 0;
}

HamnhamnMsg1::HamnhamnMsg1(const HamnhamnMsg1& other) : ::cPacket(other)
{
    copy(other);
}

HamnhamnMsg1::~HamnhamnMsg1()
{
}

HamnhamnMsg1& HamnhamnMsg1::operator=(const HamnhamnMsg1& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void HamnhamnMsg1::copy(const HamnhamnMsg1& other)
{
    this->source_var = other.source_var;
    this->msg_var = other.msg_var;
    this->destination_var = other.destination_var;
}

void HamnhamnMsg1::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->msg_var);
    doPacking(b,this->destination_var);
}

void HamnhamnMsg1::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->msg_var);
    doUnpacking(b,this->destination_var);
}

int HamnhamnMsg1::getSource() const
{
    return source_var;
}

void HamnhamnMsg1::setSource(int source)
{
    this->source_var = source;
}

const char * HamnhamnMsg1::getMsg() const
{
    return msg_var.c_str();
}

void HamnhamnMsg1::setMsg(const char * msg)
{
    this->msg_var = msg;
}

int HamnhamnMsg1::getDestination() const
{
    return destination_var;
}

void HamnhamnMsg1::setDestination(int destination)
{
    this->destination_var = destination;
}

class HamnhamnMsg1Descriptor : public cClassDescriptor
{
  public:
    HamnhamnMsg1Descriptor();
    virtual ~HamnhamnMsg1Descriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(HamnhamnMsg1Descriptor);

HamnhamnMsg1Descriptor::HamnhamnMsg1Descriptor() : cClassDescriptor("HamnhamnMsg1", "cPacket")
{
}

HamnhamnMsg1Descriptor::~HamnhamnMsg1Descriptor()
{
}

bool HamnhamnMsg1Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HamnhamnMsg1 *>(obj)!=NULL;
}

const char *HamnhamnMsg1Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HamnhamnMsg1Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int HamnhamnMsg1Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *HamnhamnMsg1Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "msg",
        "destination",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int HamnhamnMsg1Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HamnhamnMsg1Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *HamnhamnMsg1Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int HamnhamnMsg1Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HamnhamnMsg1 *pp = (HamnhamnMsg1 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HamnhamnMsg1Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HamnhamnMsg1 *pp = (HamnhamnMsg1 *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return oppstring2string(pp->getMsg());
        case 2: return long2string(pp->getDestination());
        default: return "";
    }
}

bool HamnhamnMsg1Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HamnhamnMsg1 *pp = (HamnhamnMsg1 *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setMsg((value)); return true;
        case 2: pp->setDestination(string2long(value)); return true;
        default: return false;
    }
}

const char *HamnhamnMsg1Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *HamnhamnMsg1Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HamnhamnMsg1 *pp = (HamnhamnMsg1 *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


