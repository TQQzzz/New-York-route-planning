/**
 * @file Tag.h
 * define VStatus and Etype.
 * @date May 2021
 * @author
 */

#pragma once

using VStatus = enum { UNDISCOVERED,
                       DISCOVERED,
                       VISITED };
using EType = enum { UNDETERMINED,
                     TREE,
                     CROSS,
                     FORWARD,
                     BACKWARD };