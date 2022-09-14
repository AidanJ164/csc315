#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "dsexceptions.h"
using namespace std;

template <typename Object>
class Vector
{
  public:
      explicit Vector(int initSize = 0)
          : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      { 
          cout << "Method 1" << endl;
          objects = new Object[theCapacity]; 
      }
      
    Vector( const Vector & rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    { 
        cout << "Method 2" << endl;
        objects = new Object[ theCapacity ];
        for( int k = 0; k < theSize; ++k )
            objects[ k ] = rhs.objects[ k ];
    }
    
    Vector & operator= ( const Vector & rhs )
    {
        cout << "Method 3" << endl;
        Vector copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    ~Vector()
    {
        cout << "Method 4" << endl;
        delete[] objects;
    }

    Vector( Vector && rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        cout << "Method 5" << endl;
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }
   
    Vector & operator= ( Vector && rhs )
    {    
        cout << "Method 6" << endl;
        std::swap( theSize, rhs.theSize );
        std::swap( theCapacity, rhs.theCapacity );
        std::swap( objects, rhs.objects );
        
        return *this;
    }
    
    bool empty( ) const
    { 
        cout << "Method 7" << endl;
        return size( ) == 0; 
    }
    int size() const
    {
        cout << "Method 8" << endl;
        return theSize;
    }
    int capacity() const
    {
        cout << "Method 9" << endl;
        return theCapacity;
    }

    Object & operator[]( int index )
    {
        cout << "Method 10" << endl;
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
        cout << "Method 11" << endl;
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }

    void resize( int newSize )
    {
        cout << "Method 12" << endl;
        if( newSize > theCapacity )
            reserve( newSize * 2 );
        theSize = newSize;
    }

    void reserve( int newCapacity )
    {
        cout << "Method 13" << endl;
        if( newCapacity < theSize )
            return;

        Object *newArray = new Object[ newCapacity ];
        for( int k = 0; k < theSize; ++k )
            newArray[ k ] = std::move( objects[ k ] );

        theCapacity = newCapacity;
        std::swap( objects, newArray );
        delete [ ] newArray;
    }

      // Stacky stuff
    void push_back( const Object & x )
    {
        cout << "Method 14" << endl;
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }
      // Stacky stuff
    void push_back( Object && x )
    {
        cout << "Method 15" << endl;
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }

    void pop_back( )
    {
        cout << "Method 16" << endl;
        if( empty( ) )
            throw UnderflowException{ };
        --theSize;
    }

    const Object & back ( ) const
    {
        cout << "Method 17" << endl;
        if( empty( ) )
            throw UnderflowException{ };
        return objects[ theSize - 1 ];
    }

      // Iterator stuff: not bounds checked
    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin()
    {
        cout << "Method 18" << endl;
        return &objects[0];
    }
    const_iterator begin() const
    {
        cout << "Method 19" << endl;
        return &objects[0];
    }
    iterator end()
    {
        cout << "Method 20" << endl;
        return &objects[size()];
    }
    const_iterator end() const
    {
        cout << "Method 21" << endl;
        return &objects[size()];
    }

    static const int SPARE_CAPACITY = 2;

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};

#endif
