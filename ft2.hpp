#ifndef FT2_HPP
#define FT2_HPP

#include "ft.hpp"

namespace ft
{
	template<class node, class _value_type, class _roo>
	class map_const_iterator
	{
		public:
			node*																	current_node;
			_roo*																	root;
			typedef typename ft::random_access_iterator_tag							iterator_category;
			typedef typename ft::iterator_traits<_value_type*>::value_type			value_type;
			typedef typename ft::iterator_traits<_value_type*>::difference_type		difference_type;
			typedef typename ft::iterator_traits<_value_type*>::pointer				pointer;
			typedef typename ft::iterator_traits<_value_type*>::reference			reference;
		
		public:
			map_const_iterator() : current_node(), root()
			{}

			explicit map_const_iterator (node* node_, _roo* _root) : current_node(node_), root(_root)
			{}
			
			map_const_iterator (const map_const_iterator<node, _value_type, node>& rev_it) : current_node(rev_it.current_node), root(rev_it.root)
			{}
			
			map_const_iterator(const ft::map_iterator<node, _value_type, node>& rev_it) : current_node(rev_it.current_node), root(rev_it.root)
			{ }
			
			map_const_iterator& operator=(const map_const_iterator<node, _value_type, node>& rev_it)
			{
				current_node = rev_it.current_node;
				root = rev_it.root;
				return (*this);
			}

			map_const_iterator operator ++ (int) const     
			{
				map_const_iterator tmp(*this);
				++*this;
				return (tmp);
			}

			map_const_iterator operator ++ () const       
			{
				if (current_node->right && current_node->right->data)
				{
					current_node = current_node->right;
					while (current_node->left->data)
						current_node = current_node->left;
				}
				else
				{
					if (current_node == last(root))
						current_node = current_node->right;
					else
					{
						while (current_node != current_node->p->left)
							current_node = current_node->p;
						current_node = current_node->p;
					}
					
				}
				return (*this);
			}
			
			map_const_iterator operator ++ (int)         
			{
				map_const_iterator tmp(*this);
				++*this;
				return (tmp);
			}

			map_const_iterator operator ++ ()       
			{
				if (current_node->right && current_node->right->data)
				{
					current_node = current_node->right;
					while (current_node->left->data)
						current_node = current_node->left;
				}
				else
				{
					if (current_node == last(root))
						current_node = current_node->right;
					else
					{
						while (current_node != current_node->p->left)
							current_node = current_node->p;
						current_node = current_node->p;
					}
					
				}
				return (*this);
			}

			map_const_iterator operator -- ()              
			{
				if (current_node->left && current_node->left->data)
				{
					current_node = current_node->left;
					while (current_node->right->data)
						current_node = current_node->right;
				}
				else
				{
					if (current_node == first(root))
						current_node = current_node->left;
					else
					{
						while (current_node != current_node->p->right)
							current_node = current_node->p;
						current_node = current_node->p;
					}
				}
				return (*this);
			}

			node* last(_roo* t) const
			{
				_roo* tmp = t;
				while (tmp->right->right)
					tmp = tmp->right;
				return tmp;
			}

			node* first(_roo* t) const
			{
				_roo* tmp = t;
				while (tmp->left->left)
					tmp = tmp->left;
				return tmp;
			}
			
			map_const_iterator operator -- (int)              
			{
				map_const_iterator tmp(*this);
				--*this;
				return (tmp);
			}
	
			reference operator*() const 
			{
				pointer tmp = (*current_node).data;
				return *tmp;
			}
			pointer operator->() const 
			{
				pointer tmp = (*current_node).data;
				return &*tmp;
			}
	};
	
	template<class node, class _value_type, class _roo>
	bool operator==( const ft::map_const_iterator<node, _value_type, _roo>& lhs,
                 const ft::map_const_iterator<node, _value_type, _roo>& rhs )   
	{
		if (lhs.root != rhs.root && lhs.current_node != rhs.current_node)
			return false;
		return true;
	}

	template<class node, class _value_type, class _roo>
	bool operator!=( const ft::map_const_iterator<node, _value_type, _roo>& lhs,
                 const ft::map_const_iterator<node, _value_type, _roo>& rhs )   
	{
		if (lhs.root == rhs.root && lhs.current_node == rhs.current_node)
			return false;
		return true;
	}
}

#endif