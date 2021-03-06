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

#ifndef INCLUDED_NIBBLER
#define INCLUDED_NIBBLER

#define NIBBLER_FEATURE_DATE
//#undef  NIBBLER_FEATURE_DATE

#define NIBBLER_FEATURE_REGEX
//#undef  NIBBLER_FEATURE_REGEX

#include <string>
#include <vector>

class Nibbler
{
public:
  Nibbler ();                          // Default constructor
  Nibbler (const std::string&);        // Constructor
  Nibbler (const Nibbler&);            // Copy constructor
  Nibbler& operator= (const Nibbler&); // Assignment operator
  ~Nibbler ();                         // Destructor

  bool getUntil (char, std::string&);
  bool getUntil (const std::string&, std::string&);
#ifdef NIBBLER_FEATURE_REGEX
  bool getUntilRx (const std::string&, std::string&);
#endif
  bool getUntilOneOf (const std::string&, std::string&);
  bool getUntilWS (std::string&);
  bool getUntilEOL (std::string&);
  bool getUntilEOS (std::string&);

/*
  bool getAllOneOf (const std::string&, std::string&);
*/

  bool getN (const int, std::string&);
  bool getQuoted (char, std::string&, bool quote = false);
  bool getDigit (int&);
  bool getDigit6 (int&);
  bool getDigit4 (int&);
  bool getDigit2 (int&);
  bool getInt (int&);
  bool getHex (int&);
  bool getUnsignedInt (int&);
  bool getNumber (std::string&);
  bool getNumber (double&);
  bool getUnsignedNumber (double&);
  bool getLiteral (const std::string&);
#ifdef NIBBLER_FEATURE_REGEX
  bool getRx (const std::string&, std::string&);
#endif
  bool getUUID (std::string&);
  bool getPartialUUID (std::string&);
  bool getDateISO (time_t&);
  bool parseDigits(std::string::size_type&, int&, unsigned int, bool strict = true);
#ifdef NIBBLER_FEATURE_DATE
  bool getDate (const std::string&, time_t&);
#endif
  bool getOneOf (const std::vector <std::string>&, std::string&);
  bool getName (std::string&);
  bool getWord (std::string&);

  bool skipN (const int quantity = 1);
  bool skip (char);
  bool skipAll (char);
  bool skipAllOneOf (const std::string&);
  bool skipWS ();
#ifdef NIBBLER_FEATURE_REGEX
  bool skipRx (const std::string&);
#endif

  void getRemainder (std::string&);

  char next ();
  std::string next (const int quantity);

  std::string::size_type cursor ();
  std::string::size_type save ();
  std::string::size_type restore ();
  const std::string& str () const;

  bool depleted ();

  static bool isPunctuation (char);
  std::string dump ();

private:
  std::string _input;
  std::string::size_type _length;
  std::string::size_type _cursor;
  std::string::size_type _saved;
};

#endif
////////////////////////////////////////////////////////////////////////////////
