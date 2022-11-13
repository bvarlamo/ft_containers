#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace ft
{
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
	
		return (first1 == last1) && (first2 != last2);
	};

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
	
		return (first1 == last1) && (first2 != last2);
	};

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	};

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	};

}

namespace ft
{
	template <bool var, class T >
	struct is_integral
	{
		static const bool	value = var;
		typedef T			type;
	};

	template < typename >
	struct integral_type : public is_integral< false, bool > {};

	template <>
	struct integral_type<bool> : public is_integral< true, bool > {};

	template <>
        struct integral_type<char> : public is_integral<true, char> {};

    template <>
        struct integral_type<signed char> : public is_integral<true, signed char> {};

    template <>
        struct integral_type<short int> : public is_integral<true, short int> {};

    template <>
        struct integral_type<int> : public is_integral<true, int> {};

    template <>
        struct integral_type<long int> : public is_integral<true, long int> {};

    template <>
        struct integral_type<long long int> : public is_integral<true, long long int> {};

    template <>
        struct integral_type<unsigned char> : public is_integral<true, unsigned char> {};

    template <>
        struct integral_type<unsigned short int> : public is_integral<true, unsigned short int> {};

    template <>
        struct integral_type<unsigned int> : public is_integral<true, unsigned int> {};

    template <>
        struct integral_type<unsigned long int> : public is_integral<true, unsigned long int> {};
    
    template <>
        struct integral_type<unsigned long long int> : public is_integral<true, unsigned long long int> {};

	template <typename T>
        struct is_integrals : public integral_type<T> { };
}

namespace ft
{
	template < bool, typename T = void >
	struct enable_if
	{};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

namespace ft
{
	struct random_access_iterator_tag {};
}

namespace ft
{
	struct bidirectional_iterator_tag {};
}

namespace ft 
{
    template <class Iterator>
    struct iterator_traits
	{
        typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
		typedef typename Iterator::iterator_category 	iterator_category;
    };

	template <class T>
    struct iterator_traits<T*>
	{
		typedef T									value_type;
        typedef T*            						pointer;
        typedef T&            						reference;
        typedef std::ptrdiff_t						difference_type;
		typedef ft::random_access_iterator_tag		iterator_category;
    };

	template <class T>
    struct iterator_traits<const T*>
	{
        typedef std::ptrdiff_t							difference_type;
		typedef T									value_type;
        typedef const T*            				pointer;
        typedef const T&            				reference;
		typedef ft::random_access_iterator_tag		iterator_category;
    };
}

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		// private:
		// 	Iterator	_it;
		protected:
			Iterator	current;
		public:
			typedef Iterator													Iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
		
			reverse_iterator() :current()
			{}

			explicit reverse_iterator (Iterator_type it) : current(it)
			{}

			template <class Iter>  
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : current(rev_it.base())
			{}

			Iterator_type base() const
			{
				return (current);
			}

			reverse_iterator& operator=(const reverse_iterator& src) 
			{
				current = src.base();
				return *this;
			}

			reverse_iterator& operator ++ ()              
			{
				--current;
				return *this;
			}

			reverse_iterator& operator -- ()              
			{
				++current;
				return *this;
			}

			reverse_iterator operator ++ (int)      
			{
				reverse_iterator tmp(*this);
				--current;
				return tmp;
			}

			reverse_iterator operator -- (int)       
			{
				reverse_iterator tmp(*this);
				++current;
				return tmp;
			}

			reverse_iterator operator += (difference_type n)       
			{
				current -= n; 
				return *this;
			}

			reverse_iterator operator -= (difference_type n)      
			{
				current += n; 
				return *this;
			}

			reverse_iterator operator + (difference_type n) const  
			{
				return reverse_iterator(current - n);
			}

			reverse_iterator operator - (difference_type n) const  
			{
				return reverse_iterator(current + n);
			}

			reference operator*() const 
			{
				Iterator tmp = current; 
				return *--tmp;
			}
			pointer operator->() const 
			{
				return &(operator*());
			}
			
			reference operator[] (difference_type n) const
			{
				return *(*this + n);
			}

	};

	template<class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )   
	{
		return lhs.base() == rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
	{
		return lhs.base() != rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return lhs.base() > rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
	{
		return lhs.base() >= rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return lhs.base() < rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
	{
		return lhs.base() <= rhs.base();
	}

	template< class Iter >
	ft::reverse_iterator<Iter>
    	operator+( typename ft::reverse_iterator<Iter>::difference_type n,
               const ft::reverse_iterator<Iter>& it )
	{
		return ft::reverse_iterator<Iter>(it.base() - n);
	}

	template< class Iterator1, class Iterator2 >
	typename ft::reverse_iterator<Iterator1>::difference_type
    operator-( const ft::reverse_iterator<Iterator1>& lhs,
               const ft::reverse_iterator<Iterator2>& rhs )
	{
		return rhs.base() - lhs.base();
	}
}

namespace	ft
{
	template< class T1, class T2>
	struct	pair
	{
		typedef T1		first_type;
		typedef T2		second_type;
		T1		first;
		T2		second;
		
		pair() : first(), second()
		{
		}

		pair( const T1& x, const T2& y) : first(x), second(y)
		{
		}

		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second)
		{
			
		}
		
		pair& operator=(const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}
	};
	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
}

namespace	ft
{
	template <class T1, class T2>
	ft::pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1, T2>(x, y) );
	}
}


#endif