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
		public:

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			// typedef ft::map_iterator<node, value_type>			iterator;
			// typedef const_pointer								const_iterator;
			// typedef ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:

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

				node(node* _p)
				{
					data = NULL;
					left = NULL;
					right = NULL;
					isred = false;
					p = _p;
				}

				node(allocator_type alloc, value_type _data, node* _p)
				{
					// std::cout<< "node constructor" << std::endl;
					_alloc = alloc;
					data = alloc.allocate(1);
					alloc.construct(data, _data.first, _data.second);
					left = new node(&*this);
					right = new node(&*this);
					isred = false;
					p = _p;
					// std::cout<< "----" << data->first << "----" << data->second <<std::endl;
				}

				~node()
				{
					// std::cout<< "node destructor" << std::endl;
					if (data)
					{
						_alloc.destroy(data);
						_alloc.deallocate(data, 1);
					}
					if (left)
						delete left;
					if (right)
						delete right;
				}
			};

			node*			root;
			node**			current;
			size_type		size;
			allocator_type	_alloc;
			key_compare		_comp;

		public:
			typedef ft::map_iterator<node, value_type, node>	iterator;
			typedef const_pointer								const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			void left_rotate(node& x)
			{
				node*	y = x.right;
				x.right = y->left;
				if (y->left && y->left->data != NULL)
					y->left->p = &x;
				y->p = x.p;
				if (x.p== NULL)
					root = y;
				else if (x.p && &x == x.p->left)
					x.p->left = y;
				else
					x.p->right = y;
				y->left = &x;
				x.p = y;
			}

			void right_rotate(node& x)
			{
				node*	y = x.left;
				x.left = y->right;
				if (y->right->data != NULL)
					y->right->p = &x;
				y->p = x.p;
				if (x.p == NULL)
					root = y;
				else if (x.p && &x == x.p->right)
					x.p->right = y;
				else
					x.p->left = y;
				y->right = &x;
				x.p = y;
			}

			void insert_fixup(node& z)
			{
				node*	y;
				while (z.p->isred)
				{
					if (z.p == z.p->p->left)
					{
						y = z.p->p->right;
						if (y->isred)
						{
							z.p->isred = false;
							y->isred = false;
							z.p->p->isred = true;
							z = z.p->p;
						}
						else
						{
							if (&z == z.p->right)
							{
								std::cout<<"ss "<<z.data->first<<std::endl;
								z = *z.p;
								std::cout<<"ss1 "<<z.data->first<<std::endl;
								std::cout<<"ss2 "<<z.right->data->first<<std::endl;
								left_rotate(z);
								std::cout<<"ss "<<z.right->data->first<<std::endl;
							}
							z.p->isred = false;
							z.p->p->isred = true;
							right_rotate(*z.p->p);
							std::cout<<"ss "<<&z<<std::endl;
						}
					}
					else 
					{
						y = z.p->p->left;
						if (y->isred)
						{
							z.p->isred = false;
							y->isred = false;
							z.p->p->isred = true;
							z = z.p->p;
						}
						else
						{
							if (&z == z.p->left)
							{
								z = *z.p;
								right_rotate(z);
							}
							z.p->isred = false;
							z.p->p->isred = true;
							left_rotate(*z.p->p);
						}
					}
					root->isred = false;
				}
			}

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_comp = comp;
				_alloc = alloc;
				root = NULL;
				size = 0;
				current = NULL;
			}
		
			iterator end()
			{
				current = &root;
				while ((*current)->right)
					current = &(*current)->right;
				iterator tm((*current), root);
				return (tm);
			}

			iterator begin()
			{
				current = &root;
				while ((*current)->left->data)
					current = &(*current)->left;
				iterator tm((*current), root);
				return (tm);
			}

			reverse_iterator rbegin()
			{
				reverse_iterator it(end());
				return (it);
			}

			reverse_iterator rend()
			{
				reverse_iterator it(begin());
				return (it);
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

			~map()
			{
				delete root;
			}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (root == NULL)
				{
					root = new node(_alloc, val, NULL);
					current = &root;
					root->isred = false;
					size++;
					return (ft::pair<iterator, bool>(iterator((*current), root), true));
				}
				current = &root;
				node *p;
				while ((*current)->data != NULL)
				{
					p = *current;
					if ((*current)->data && (*current)->data->first == val.first)
						return(ft::pair<iterator, bool>((iterator((*current), root)), false));
					else if (value_compare(_comp).comp((*current)->data->first, val.first))
						current = &(*current)->right;
					else
						current = &(*current)->left;
				}
				delete *current;
				*current = new node(_alloc, val, p);
				(*current)->isred = true;
				std::cout<<"aa "<<root->data->first<<std::endl;
				if (root->left->left)
					std::cout<<"a1 "<<root->left->data->first<<std::endl;
				if (root->left->right->left)
					std::cout<<"a2 "<<root->left->right->data->first<<std::endl;
				insert_fixup(*(*current));
				std::cout<<"aa "<<root->data->first<<std::endl;
				if (root->left->left)
					std::cout<<"a1 "<<root->left->data->first<<std::endl;
				if (root->left->right->left)
					std::cout<<"a2 "<<root->left->right->data->first<<std::endl;
				size++;
				return (ft::pair<iterator, bool>((iterator((*current), root)), true));
			}
	};
}

#endif