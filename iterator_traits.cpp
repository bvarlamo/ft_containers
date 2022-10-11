/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarlamo <bvarlamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:03:20 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/10/06 12:15:22 by bvarlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template <class T>
	struct iteraitor_traits
	{
		typedef typename T::values_type			values_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
	};
};

namespace ft
{
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T									values_type;
		typedef std::ptrdiff_t						difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T*									pointer;
		typedef T&									reference;
	};
};

namespace ft
{
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef T									values_type;
		typedef std::ptrdiff_t						difference_type;
		typedef std::random_access_iterator_tag		iterator_category;
		typedef const T*							pointer;
		typedef const T&							reference;
	};
};