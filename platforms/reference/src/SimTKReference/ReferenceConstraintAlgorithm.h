
/* Portions copyright (c) 2009 Stanford University and Simbios.
 * Contributors: Peter Eastman
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS, CONTRIBUTORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __ReferenceConstraintAlgorithm_H__
#define __ReferenceConstraintAlgorithm_H__

/**
 * This abstract class defines the interface which constraint algorithms must implement.
 */
class ReferenceConstraintAlgorithm {
public:

    virtual ~ReferenceConstraintAlgorithm() {};

      /**---------------------------------------------------------------------------------------

         Apply constraint algorithm

         @param numberOfAtoms    number of atoms
         @param atomCoordinates  atom coordinates
         @param atomCoordinatesP atom coordinates prime
         @param inverseMasses    1/mass

         @return ReferenceDynamics::DefaultReturn if converge; else
          return ReferenceDynamics::ErrorReturn

         --------------------------------------------------------------------------------------- */

    virtual int apply(int numberOfAtoms, RealOpenMM** atomCoordinates,
                     RealOpenMM** atomCoordinatesP, RealOpenMM* inverseMasses) = 0;
};

// ---------------------------------------------------------------------------------------

#endif // __ReferenceConstraintAlgorithm_H__