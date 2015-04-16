/*
** -*- coding: utf-8 -*-
**
** File: common.h
** by Arzaroth Lekva
** arzaroth@arzaroth.com
**
*/

#ifndef COMMON_H_
# define COMMON_H_

# if PY_MAJOR_VERSION >= 3
#  define Py_TPFLAGS_HAVE_ITER 0
# endif

# include <rapidxml.hpp>

/*
** Objects definitions
*/

typedef struct {
  PyObject_HEAD
  rapidxml::xml_base<>* underlying_obj;
  rapidxml::xml_document<>* document;
} rapidxml_BaseObject;

typedef struct {
  rapidxml_BaseObject base;
} rapidxml_NodeObject;

typedef struct {
  rapidxml_BaseObject base;
} rapidxml_AttributeObject;

typedef struct {
  rapidxml_NodeObject base;
} rapidxml_DocumentObject;

/*
** Iterators definitions
*/

typedef struct {
  PyObject_HEAD
  PyObject* parent;
  rapidxml::xml_node<>* node;
} rapidxml_NodeIteratorObject;

typedef struct {
  PyObject_HEAD
  PyObject* parent;
  rapidxml::xml_attribute<>* attribute;
} rapidxml_AttributeIteratorObject;

/*
** Types
*/

extern PyTypeObject rapidxml_BaseType;
extern PyTypeObject rapidxml_NodeType;
extern PyTypeObject rapidxml_AttributeType;
extern PyTypeObject rapidxml_DocumentType;

extern PyTypeObject rapidxml_NodeIteratorType;
extern PyTypeObject rapidxml_AttributeIteratorType;

/*
** Exceptions
*/

extern PyObject* rapidxml_RapidXmlError;

/*
** Utility functions
*/

int _parse_args_for_name(PyObject*, PyObject*, const char**);
PyObject* _bind_result(rapidxml_BaseObject*, rapidxml::xml_base<>*, PyTypeObject*);

/*
** Type check macros
*/

# define IS_DOC(o) (Py_TYPE(o) == &rapidxml_DocumentType)
# define IS_NODE(o) (IS_DOC(o) || (Py_TYPE(o) == &rapidxml_NodeType))
# define IS_ATTR(o) (Py_TYPE(o) == &rapidxml_AttributeType)
# define IS_BASE(o) (IS_ATTR(o) || IS_NODE(o) || (Py_TYPE(o) == &rapidxml_BaseType))

# define IS_NODEITER(o) (Py_TYPE(o) == &rapidxml_NodeIteratorType)
# define IS_ATTRITER(o) (Py_TYPE(o) == &rapidxml_AttributeIteratorType)

#endif /* !COMMON_H_ */