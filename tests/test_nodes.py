#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# File: test_nodes.py
# by Arzaroth Lekva
# arzaroth@arzaroth.com
#

def test_first_node(init_rapidxml):
    root = init_rapidxml.first_node()
    assert root.name == "root"
    assert root.value == ""
    assert root.unparse() == init_rapidxml.unparse()
    assert root.first_node() == root.first_node("test")
    assert root.first_node() != root.first_node("test2")

def test_last_node(init_rapidxml):
    root = init_rapidxml.first_node()
    assert root.first_node() != root.last_node()
    assert root.first_node("test2") == root.last_node("test2")
    assert root.last_node().value == "some text"

def test_nested_node(init_rapidxml):
    test = init_rapidxml.first_node().first_node("test")
    assert test.name == "test"
    assert test.value == ""
    test2 = init_rapidxml.first_node().first_node("test2")
    assert test2.name == "test2"
    assert test2.value == ""
