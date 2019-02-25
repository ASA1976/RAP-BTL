# Relational Association Programming - Basic Template Library

## Introduction

This template library is a proving ground for a type strict C++ (2014) dialect 
(language subset) intended for a systems programming audience.  This template
library is not currently being tested for production use and should not be used
in a production environment without full testing.

## The Library

The RAP-BTL library has been designed for systems programming tasks.  This means
that it must be designed to either be very efficient or very sure since
systems programming ranges between high performance and high surety.  That is
why funtionality is provided as base templates and safe versions which verify 
arguments (etc.).

## The Paradigm

For those of you unaware of my paradigm proposal, the [Relational Association
Paradigm](http://github.com/ASA1976/RAP) is a proposed extension to procedural 
programming with the additional language requirements of source modularity 
(associations and relations) as well as run-time determinate function 
referencing (objectifications).

## The Syntax

The syntactic dialect is based out of the C++ 2014 specification strictly.
First is the fact that this syntax is RAP based, not object-oriented.  This 
means writing traditional functions and producing function reference tables.
Rules which promote type strictness are no inheritence and no user-defined 
conversion operators.  Rules which promote system security include the use of
references over pointers where appropriate, in the case of references to 
functions especially.

## The Conversation

There is a working draft document containing a more detailed breakdown of the 
syntactic boundaries.  Please feel free to [contact 
me](mailto:rap.paradigm@gmail.com) if you wish to discuss or collaborate.

