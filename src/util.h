////////////////////////////////////////////////////////////////////////////////
// taskd - Taskserver
//
// Copyright 2010 - 2014, Göteborg Bit Factory.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDED_UTIL
#define INCLUDED_UTIL

#include <string>
#include <vector>
#ifdef FREEBSD
#include <uuid.h>
#else
#include <uuid/uuid.h>
#endif

bool confirm (const std::string&);
std::string formatBytes (size_t);
std::string formatTime (time_t);
int autoComplete (const std::string&, const std::vector<std::string>&, std::vector<std::string>&, int minimum = 1);

#ifndef HAVE_UUID_UNPARSE_LOWER
void uuid_unparse_lower (uuid_t uu, char *out);
#endif
const std::string uuid ();

const std::string encode (const std::string&);
const std::string decode (const std::string&);
const std::string escape (const std::string&, char);

#ifndef HAVE_TIMEGM
  time_t timegm (struct tm *tm);
#endif

#endif
////////////////////////////////////////////////////////////////////////////////
