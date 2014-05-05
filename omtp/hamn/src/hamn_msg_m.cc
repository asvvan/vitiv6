//
// Generated file, do not edit! Created by opp_msgc 4.4 from hamn_msg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "hamn_msg_m.h"

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




Register_Class(hamn_msg);

hamn_msg::hamn_msg(const char *name, int kind) : ::cPacket(name,kind)
{
    this->source_var = 0;
    this->destination_var = 0;
    this->msg_var = 0;
    this->type_var = 0;
    this->lifetime_var = 0;
}

hamn_msg::hamn_msg(const hamn_msg& other) : ::cPacket(other)
{
    copy(other);
}

hamn_msg::~hamn_msg()
{
}

hamn_msg& hamn_msg::operator=(const hamn_msg& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void hamn_msg::copy(const hamn_msg& other)
{
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
    this->msg_var = other.msg_var;
    this->type_var = other.type_var;
    this->lifetime_var = other.lifetime_var;
}

void hamn_msg::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->msg_var);
    doPacking(b,this->type_var);
    doPacking(b,this->lifetime_var);
}

void hamn_msg::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->msg_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->lifetime_var);
}

const char * hamn_msg::getSource() const
{
    return source_var.c_str();
}

void hamn_msg::setSource(const char * source)
{
    this->source_var = source;
}

const char * hamn_msg::getDestination() const
{
    return destination_var.c_str();
}

void hamn_msg::setDestination(const char * destination)
{
    this->destination_var = destination;
}

const char * hamn_msg::getMsg() const
{
    return msg_var.c_str();
}

void hamn_msg::setMsg(const char * msg)
{
    this->msg_var = msg;
}

int hamn_msg::getType() const
{
    return type_var;
}

void hamn_msg::setType(int type)
{
    this->type_var = type;
}

int hamn_msg::getLifetime() const
{
    return lifetime_var;
}

void hamn_msg::setLifetime(int lifetime)
{
    this->lifetime_var = lifetime;
}

class hamn_msgDescriptor : public cClassDescriptor
{
  public:
    hamn_msgDescriptor();
    virtual ~hamn_msgDescriptor();

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

Register_ClassDescriptor(hamn_msgDescriptor);

hamn_msgDescriptor::hamn_msgDescriptor() : cClassDescriptor("hamn_msg", "cPacket")
{
}

hamn_msgDescriptor::~hamn_msgDescriptor()
{
}

bool hamn_msgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<hamn_msg *>(obj)!=NULL;
}

const char *hamn_msgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int hamn_msgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int hamn_msgDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *hamn_msgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "destination",
        "msg",
        "type",
        "lifetime",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int hamn_msgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifetime")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *hamn_msgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *hamn_msgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int hamn_msgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    hamn_msg *pp = (hamn_msg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string hamn_msgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    hamn_msg *pp = (hamn_msg *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSource());
        case 1: return oppstring2string(pp->getDestination());
        case 2: return oppstring2string(pp->getMsg());
        case 3: return long2string(pp->getType());
        case 4: return long2string(pp->getLifetime());
        default: return "";
    }
}

bool hamn_msgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    hamn_msg *pp = (hamn_msg *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource((value)); return true;
        case 1: pp->setDestination((value)); return true;
        case 2: pp->setMsg((value)); return true;
        case 3: pp->setType(string2long(value)); return true;
        case 4: pp->setLifetime(string2long(value)); return true;
        default: return false;
    }
}

const char *hamn_msgDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *hamn_msgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    hamn_msg *pp = (hamn_msg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


