#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "ft.hpp"
#include <memory>
#include <functional>

namespace	ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class	map
	{
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const Key, T>					value_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef pointer									iterator;
		typedef const_pointer							const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

			public:
				typedef bool 			result_type;
				typedef value_type 		first_argument_type;
				typedef value_type 		second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};
		struct	node
		{
			value_type*		data;
			bool			isred;
			allocator_type _alloc;

			node*		left;
			node*		right;
			node*		p;

			node(allocator_type alloc, value_type _data, node* _p)
			{
				std::cout<< "node constructor" << std::endl;
				_alloc = alloc;
				data = alloc.allocate(1);
				alloc.construct(data, _data.first, _data.second);
				left = NULL;
				right = NULL;
				isred = false;
				p = _p;
				std::cout<< "----" << data->first << "----" << data->second <<std::endl;
			}

			~node()
			{
				std::cout<< "node destructor" << std::endl;
				_alloc.destroy(data);
				_alloc.deallocate(data, 1);

			}
		};

		node*			root;
		node*			current;
		size_type		size;
		allocator_type	_alloc;
		key_compare		_comp;

		public:

			void	print()
			{
				std::cout<< root->data->first << "**" << root->data->second <<std::endl;
				std::cout<< root->right->data->first << "**" << root->right->data->second <<std::endl;
				std::cout<< root->right->right->data->first << "**" << root->right->data->second <<std::endl;
			}

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				std::cout<< "default constructor" << std::endl;
				_comp = comp;
				_alloc = alloc;
				root = NULL;
				size = 0;
				current = root;
				std::cout<< "heljo" << std::endl;
				// std::cout<< root->data->first << "----" << root->data->second <<std::endl;
			}
		
			// template <class InputIterator> 
			// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			// {
			// 	std::cout<< "first and last constructor" << std::endl;
			// 	_comp = comp;
			// 	_alloc = alloc;
			// 	node tmp(_alloc, first, NULL);
			// 	root = &tmp;
			// 	current = root;
			// 	size = 1;
			// 	for(InputIterator tmp2 = ++first; tmp != last; tmp++ )
			// 	{
			// 		if (_comp(current->data, tmp2))
			// 		{
			// 			node tmp1(_alloc, tmp2, current);
			// 			current->data->right = &tmp1;
			// 			current = current->data->right;
			// 		}
			// 		else if (current->data->first == tmp2->first)
			// 		{
			// 			std::cout<< "already exists" <<std::endl;
			// 		}
			// 		else
			// 		{
			// 			node tmp1(_alloc, tmp2, current);
			// 			current->data->left = &tmp1;
			// 			current = current->data->left;
			// 		}
			// 	}
				
			// 	std::cout<< "heljo" << std::endl;
			// 	std::cout<< root->data->first << "----" << root->data->second <<std::endl;
			// }

			// map (const map& x)
			// {

			// }

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				current = root;
				node *p;
				while (current != NULL)
				{
					std::cout<< current <<std::endl;
					p = current;
					if (current->data->first == val.first)
						return(ft::pair<value_type*, bool>(current->data, false));
					else if (value_compare(_comp).comp(current->data->first, val.first))
					{
						current = current->right;
						std::cout<< current << "--" << &current <<std::endl; 
						std::cout<< &current->right << "--" << &current->right <<std::endl; 
					}
					else
					{
						current = current->left;
						std::cout<< current << "--" << &current <<std::endl; 
					}
					std::cout<< current <<std::endl;
					std::cout<< "aaa"<<std::endl;
				}
				if (root == NULL)
				{
					root = new node(_alloc, val, p);
					current = root;
				}
				else
					current = new node(_alloc, val, p);
				size++;
				std::cout<< "1:1= " << root->data->first << "1:2= " << root->data->second <<std::endl;
				std::cout<< "1:1= " << current->data->first << "1:2= " << current->data->second <<std::endl;
				return (ft::pair<value_type*, bool>(current->data, true));
			}
	};
}

#endif