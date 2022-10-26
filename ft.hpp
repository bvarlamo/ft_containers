/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:47:07 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/10/26 17:55:07 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
#define FT_HPP

// namespace ft
// {
// 	template <class _value, class _compare, class _alloc>
// 	class	tree
// 	{
// 		_value*			data;
// 		bool			isred;
// 		_alloc			alloc;
// 		std::size_t		size;

// 		node*		left;
// 		node*		right;
// 		node*		p;

// 		node(allocator_type _alloc, value_type _data, node* _p)
// 		{
// 			// std::cout<< "node constructor" << std::endl;
// 			alloc = _alloc;
// 			data = alloc.allocate(1);
// 			alloc.construct(data, _data.first, _data.second);
// 			left = NULL;
// 			right = NULL;
// 			isred = false;
// 			p = _p;
// 			// std::cout<< "----" << data->first << "----" << data->second <<std::endl;
// 		}

// 		~node()
// 		{
// 			// std::cout<< "node destructor" << std::endl;
// 			_alloc.destroy(data);
// 			_alloc.deallocate(data, 1);

// 		}
// 		public:
// 			ft::pair<_value,bool> insert (const _value& val)
// 			{
// 				if (root == NULL)
// 				{
// 					root = new node(_alloc, val, NULL);
// 					current = &root;
// 					size++;
// 					return (ft::pair<value_type*, bool>((*current)->data, true));
// 				}
// 				current = &root;
// 				node *p;
// 				while (*current != NULL)
// 				{
// 					p = *current;
// 					if ((*current)->data->first == val.first)
// 						return(ft::pair<value_type*, bool>((*current)->data, false));
// 					else if (value_compare(_comp).comp((*current)->data->first, val.first))
// 						current = &(*current)->right;
// 					else
// 						current = &(*current)->left;
// 				}
// 				*current = new node(_alloc, val, p);
// 				size++;
// 				return (ft::pair<value_type*, bool>((*current)->data, true));
// 			}
// 	};
// }


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
        typedef std::ptrdiff_t							difference_type;
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
		private:
			Iterator	_it;
		protected:
			Iterator	current;
		public:
			typedef Iterator													Iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
		
			reverse_iterator() : _it(), current()
			{}

			explicit reverse_iterator (Iterator_type it) : _it(it), current(it)
			{}

			template <class Iter>  
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()), current(rev_it.base())
			{}

			Iterator_type base() const
			{
				return (current);
			}

			reverse_iterator operator ++ ()              
			{
				--current;
				return *this;
			}

			reverse_iterator operator -- ()              
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

	template< class Iterator >
	typename ft::reverse_iterator<Iterator>::difference_type
    operator-( const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs )
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

namespace ft
{
	template<class node, class _value_type>
	class map_iterator
	{
		public:
			// typedef _value_type								value_type;
			// typedef _value_type*            				pointer;
			// typedef _value_type&            				reference;
			// typedef std::ptrdiff_t							difference_type;
			// typedef ft::random_access_iterator_tag			iterator_category;
			typedef typename ft::iterator_traits<_value_type*>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<_value_type*>::value_type			value_type;
			typedef typename ft::iterator_traits<_value_type*>::difference_type		difference_type;
			typedef typename ft::iterator_traits<_value_type*>::pointer				pointer;
			typedef typename ft::iterator_traits<_value_type*>::reference			reference;
			node*			current_node;
		
		public:
			map_iterator() : current_node()
			{}

			explicit map_iterator (node* node_) : current_node(node_)
			{}
			
			map_iterator (const map_iterator<node, _value_type>& rev_it) : current_node(rev_it.current_node)
			{}
			
			map_iterator& operator=(const map_iterator<node, _value_type>& rev_it)
			{
				current_node = rev_it.current_node;
				// value = rev_it.value;
				return (*this);
			}
			
			map_iterator operator ++ (int)              
			{
				map_iterator tmp(*this);
				++*this;
				return (tmp);
			}

			map_iterator operator ++ ()              
			{
				if (current_node->right)
				{
					current_node = current_node->right;
					while (current_node->left)
						current_node = current_node->left;
				}
				else
				{
					if (current_node->p->left == current_node)
					{
						current_node = current_node->p;
					}
					else
					{
						current_node = current_node->p;
						current_node = current_node->p;
					}
					
				}
				return (*this);
			}

			map_iterator operator -- ()              
			{
				if (current_node->left)
				{
					current_node = current_node->left;
					while (current_node->right)
						current_node = current_node->right;
				}
				else
				{
					if (current_node->p->right == current_node)
					{
						current_node = current_node->p;
					}
					else
					{
						current_node = current_node->p;
						current_node = current_node->p;
					}
					
				}
				return (*this);
			}

			map_iterator operator -- (int)              
			{
				map_iterator tmp(*this);
				--*this;
				return (tmp);
			}
	
			pointer operator*() const 
			{
				pointer tmp = (*current_node).data;
				return tmp;
			}
			pointer operator->() const 
			{
				pointer tmp = (*current_node).data;
				return tmp;
			}
	};
	
	template<class Iterator1, class Iterator2, class Iterator3, class Iterator4 >
	bool operator==( const ft::map_iterator<Iterator1, Iterator2>& lhs,
                 const ft::map_iterator<Iterator3, Iterator4>& rhs )   
	{
		return lhs.current_node == rhs.current_node;
	}

	template<class Iterator1, class Iterator2, class Iterator3, class Iterator4 >
	bool operator!=( const ft::map_iterator<Iterator1, Iterator2>& lhs,
                 const ft::map_iterator<Iterator3, Iterator4>& rhs )   
	{
		return lhs.current_node != rhs.current_node;
	}
}

#endif