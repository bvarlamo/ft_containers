#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "utils.hpp"

namespace ft
{

	template< typename T>
	class random_access_iterator
	{
		public:
			typedef typename ft::random_access_iterator_tag							iterator_category;
			typedef T																value_type;
			typedef T*           			 										pointer;
			typedef T&          			  										reference;
			typedef std::ptrdiff_t													difference_type;
		// 	typedef T															iterator_type;
		// 	typedef typename iterator_traits<iterator_type>::iterator_category 	iterator_category;
		// 	typedef typename iterator_traits<iterator_type>::value_type        	value_type;
		// 	typedef typename iterator_traits<iterator_type>::difference_type   	difference_type;
		// 	typedef typename iterator_traits<iterator_type>::pointer           	pointer;
		// 	typedef typename iterator_traits<iterator_type>::reference         	reference;
		// private:
		// 	iterator_type ptr;

		private:
			pointer 	ptr;

		public:

			random_access_iterator() : ptr() 
			{}

			random_access_iterator(pointer a) : ptr(a) 
			{}

			~random_access_iterator() 
			{}

			random_access_iterator(const random_access_iterator<T> & src) : ptr(src.ptr) 
			{}

			random_access_iterator& operator=(const random_access_iterator<T>& src) 
			{
				ptr = src.ptr;
				return *this;
			}

			random_access_iterator & operator++() 
			{
				++ptr;
				return *this;
			}

			random_access_iterator operator++(int) 
			{
				random_access_iterator tmp(*this);
				++ptr;
				return tmp;
			}

			random_access_iterator & operator--() 
			{
				--ptr;
				return *this;
			}

			random_access_iterator  operator--(int) 
			{
				random_access_iterator tmp = *this;
				--ptr;
				return tmp;
			}
			random_access_iterator operator+(const difference_type & a) const 
			{
				return ptr + a;
			}

			random_access_iterator operator-(const difference_type & a) const 
			{
				return ptr - a;
			}

			random_access_iterator & operator+=(const difference_type & a) 
			{
				ptr += a;
				return (*this);
			}
			random_access_iterator & operator-=(const difference_type & a) 
			{
				ptr -= a;
				return (*this);
			}

			pointer operator->() const 
			{
				return ptr;
			}

			reference operator*() const 
			{
				return *ptr;
			}

			reference operator[](difference_type n) const 
			{
				return *(ptr + n);
			}
		};
		template<typename A, typename B>
		bool operator==(const ft::random_access_iterator<A> & lhs, const ft::random_access_iterator<B> & rhs)
		{
			return &(*lhs) == &(*rhs);
		}

		template<typename A, typename B>
		bool operator!=(const ft::random_access_iterator<A> & lhs, const ft::random_access_iterator<B> & rhs) 
		{
			return &(*lhs) != &(*rhs);
		}

		template<typename A, typename B>
		bool operator>(const ft::random_access_iterator<A> & lhs, const ft::random_access_iterator<B> & rhs) 
		{
			return &(*lhs) > &(*rhs);
		}

		template<typename A, typename B>
		bool operator<(const ft::random_access_iterator<A> & lhs, const ft::random_access_iterator<B> & rhs) 
		{
			return &(*lhs) < &(*rhs);
		}

		template<typename A, typename B>
		bool operator<=(const ft::random_access_iterator<A> & lhs, const ft::random_access_iterator<B> & rhs) 
		{
			return &(*lhs) <= &(*rhs);
		}


		template<typename A, typename B>
		bool operator>=(const ft::random_access_iterator<A> & lhs, const ft::random_access_iterator<B> & rhs) 
		{
			return &(*lhs) >= &(*rhs);
		}



	template< typename T>
	class random_const_access_iterator
	{
		public:
			typedef typename ft::random_access_iterator_tag							iterator_category;
			typedef T																value_type;
			typedef T*           			 										pointer;
			typedef T&          			  										reference;
			typedef std::ptrdiff_t													difference_type;
			// typedef T															iterator_type;
			// typedef typename iterator_traits<iterator_type>::iterator_category 	iterator_category;
			// typedef typename iterator_traits<iterator_type>::value_type        	value_type;
			// typedef typename iterator_traits<iterator_type>::difference_type   	difference_type;
			// typedef typename iterator_traits<iterator_type>::pointer           	pointer;
			// typedef typename iterator_traits<iterator_type>::reference         	reference;
		private:
			pointer ptr;


		public:

			random_const_access_iterator() : ptr() 
			{}

			random_const_access_iterator(pointer a) : ptr(a) 
			{}

			~random_const_access_iterator() 
			{}

			random_const_access_iterator(const random_const_access_iterator<T> & src) : ptr(src.ptr) 
			{}

			random_const_access_iterator(const ft::random_access_iterator<T> & src) : ptr(src.ptr) 
			{}

			random_const_access_iterator& operator=(const random_const_access_iterator<T>& src) 
			{
				ptr = src.ptr;
				return *this;
			}

			random_const_access_iterator & operator++() 
			{
				++ptr;
				return *this;
			}

			random_const_access_iterator operator++(int) 
			{
				random_const_access_iterator tmp(*this);
				++ptr;
				return tmp;
			}

			random_const_access_iterator & operator--() 
			{
				--ptr;
				return *this;
			}

			random_const_access_iterator  operator--(int) 
			{
				random_const_access_iterator tmp = *this;
				--ptr;
				return tmp;
			}
			random_const_access_iterator operator+(const difference_type & a) const 
			{
				return ptr + a;
			}

			random_const_access_iterator operator-(const difference_type & a) const 
			{
				return ptr - a;
			}

			random_const_access_iterator & operator+=(const difference_type & a) 
			{
				ptr += a;
				return (*this);
			}
			random_const_access_iterator & operator-=(const difference_type & a) 
			{
				ptr -= a;
				return (*this);
			}

			pointer operator->() const 
			{
				return ptr;
			}

			reference operator*() const 
			{
				return *ptr;
			}

			reference operator[](difference_type n) const 
			{
				return *(ptr + n);
			}
		};
		template<typename A, typename B>
		bool operator==(const ft::random_const_access_iterator<A> & lhs, const ft::random_const_access_iterator<B> & rhs)
		{
			return &(*lhs) == &(*rhs);
		}

		template<typename A, typename B>
		bool operator!=(const ft::random_const_access_iterator<A> & lhs, const ft::random_const_access_iterator<B> & rhs) 
		{
			return &(*lhs) != &(*rhs);
		}

		template<typename A, typename B>
		bool operator>(const ft::random_const_access_iterator<A> & lhs, const ft::random_const_access_iterator<B> & rhs) 
		{
			return &(*lhs) > &(*rhs);
		}

		template<typename A, typename B>
		bool operator<(const ft::random_const_access_iterator<A> & lhs, const ft::random_const_access_iterator<B> & rhs) 
		{
			return &(*lhs) < &(*rhs);
		}

		template<typename A, typename B>
		bool operator<=(const ft::random_const_access_iterator<A> & lhs, const ft::random_const_access_iterator<B> & rhs) 
		{
			return &(*lhs) <= &(*rhs);
		}


		template<typename A, typename B>
		bool operator>=(const ft::random_const_access_iterator<A> & lhs, const ft::random_const_access_iterator<B> & rhs) 
		{
			return &(*lhs) >= &(*rhs);
		}

}

namespace ft
{
	
	template<class node, class _value_type>
	class tree_iterator
	{
		public:
			typedef typename ft::bidirectional_iterator_tag							iterator_category;
			typedef _value_type														value_type;
			typedef _value_type*            										pointer;
			typedef _value_type&            										reference;
			typedef std::ptrdiff_t													difference_type;
			node*																	current_node;


		
			tree_iterator() : current_node()
			{}

			explicit tree_iterator (node* node_) : current_node(node_)
			{}
			
			tree_iterator (const tree_iterator<node, _value_type>& rev_it) : current_node(rev_it.current_node)
			{}

			tree_iterator& operator=(const tree_iterator<node, _value_type>& rev_it)
			{
				current_node = rev_it.current_node;
				return (*this);
			}
			
			tree_iterator operator ++ (int)         
			{
				tree_iterator tmp(*this);
				++*this;
				return tmp;
			}

			tree_iterator& operator ++ ()       
			{
				if (current_node->right && current_node->right->left)
				{
					current_node = current_node->right;
					while (current_node->left->left)
						current_node = current_node->left;
				}
				else
				{
					node* t = current_node;
					while (current_node && current_node->p && current_node != current_node->p->left)
					{
						current_node = current_node->p;
					}
					if (!current_node->p)
						current_node = t->right;
					else
						current_node = current_node->p;
					
				}
				return *this;
			}

			tree_iterator& operator -- ()              
			{
				if (current_node->left && current_node->left->left)
				{
					current_node = current_node->left;
					while (current_node->right->left)
						current_node = current_node->right;
				}
				else
				{
					node* t = current_node;
					while (current_node && current_node->p && current_node != current_node->p->right)
					{
						current_node = current_node->p;
					}
					if (!current_node->p)
						current_node = t->left;
					else
						current_node = current_node->p;
				}
				return *this;
			}

			tree_iterator operator -- (int)              
			{
				tree_iterator tmp(*this);
				--*this;
				return tmp;
			}
	
			reference operator*() const 
			{
				pointer tmp = &(*current_node).data;
				return *(tmp);
			}
			pointer operator->() const 
			{
				return &(*current_node).data;
			}
	};
	
	template<class node, class _value_type>
	bool operator==( const ft::tree_iterator<node, _value_type>& lhs,
                 const ft::tree_iterator<node, _value_type>& rhs )   
	{
		if (lhs.current_node != rhs.current_node)
			return false;
		return true;
	}

	template<class node, class _value_type>
	bool operator!=( const ft::tree_iterator<node, _value_type>& lhs,
                 const ft::tree_iterator<node, _value_type>& rhs )   
	{
		if (lhs.current_node == rhs.current_node)
			return false;
		return true;
	}




	template<class node, class _value_type>
	class tree_const_iterator
	{
		public:
			typedef typename ft::bidirectional_iterator_tag							iterator_category;
			typedef const _value_type												value_type;
			typedef value_type*            											pointer;
			typedef value_type&            											reference;
			typedef std::ptrdiff_t													difference_type;
			node*																	current_node;

		
			tree_const_iterator() : current_node()
			{}

			explicit tree_const_iterator (node* node_) : current_node(node_)
			{}
			
			tree_const_iterator (const tree_const_iterator<node, _value_type>& rev_it) : current_node(rev_it.current_node)
			{}

			tree_const_iterator (const ft::tree_iterator<node, _value_type>& rev_it) : current_node(rev_it.current_node)
			{}

			tree_const_iterator& operator=(const tree_const_iterator<node, _value_type>& rev_it)
			{
				current_node = rev_it.current_node;
				return (*this);
			}
			
			tree_const_iterator operator ++ (int)         
			{
				tree_const_iterator tmp(*this);
				++*this;
				return (tmp);
			}

			tree_const_iterator& operator ++ ()       
			{
				if (current_node->right && current_node->right->left)
				{
					current_node = current_node->right;
					while (current_node->left->left)
						current_node = current_node->left;
				}
				else
				{
					node* t = current_node;
					while (current_node && current_node->p && current_node != current_node->p->left)
					{
						current_node = current_node->p;
					}
					if (!current_node->p)
						current_node = t->right;
					else
						current_node = current_node->p;
					
				}
				return (*this);
			}

			tree_const_iterator& operator -- ()              
			{
				if (current_node->left && current_node->left->left)
				{
					current_node = current_node->left;
					while (current_node->right->left)
						current_node = current_node->right;
				}
				else
				{
					while (current_node != current_node->p->right)
						current_node = current_node->p;
					current_node = current_node->p;
				}
				return (*this);
			}

			tree_const_iterator operator -- (int)              
			{
				tree_const_iterator tmp(*this);
				--*this;
				return (tmp);
			}
	
			reference operator*() const 
			{
				pointer tmp = &(*current_node).data;
				return *tmp;
			}
			pointer operator->() const 
			{
				pointer tmp = &(*current_node).data;
				return tmp;
			}
	};
	
	template<class node, class _value_type>
	bool operator==( const ft::tree_const_iterator<node, _value_type>& lhs,
                 const ft::tree_const_iterator<node, _value_type>& rhs )   
	{
		if (lhs.current_node != rhs.current_node)
			return false;
		return true;
	}

	template<class node, class _value_type>
	bool operator!=( const ft::tree_const_iterator<node, _value_type>& lhs,
                 const ft::tree_const_iterator<node, _value_type>& rhs )   
	{
		if (lhs.current_node == rhs.current_node)
			return false;
		return true;
	}
}

#endif