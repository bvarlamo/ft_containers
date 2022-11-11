#include <iostream>
#include "tree.hpp"
#include "map.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include <map>
#include <vector>

int	main()
{
	// std::vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);
	// v.push_back(4);
	// std::vector<int>::const_iterator it = v.begin();
	// *it = 11;
	// std::cout<<*it<<std::endl;

	std::map<int, int> m;
	std::pair<int, int> a(1, 11);
	std::pair<int, int> b(2, 12);
	std::pair<int, int> c(3, 13);
	std::pair<int, int> d(4, 14);
	m.insert(a);
	m.insert(b);
	m.insert(c);
	m.insert(d);

	std::map<int, int>::iterator i = m.begin();
	i->second = 111;
	std::cout<<i->second<<std::endl;

	ft::map<int, int> m1;
	ft::pair<int, int> a1(1, 11);
	ft::pair<int, int> b1(2, 12);
	ft::pair<int, int> c1(3, 13);
	ft::pair<int, int> d1(4, 14);
	m1.insert(a1);
	m1.insert(b1);
	m1.insert(c1);
	m1.insert(d1);

	ft::map<int, int>::const_iterator i1 = m1.begin();
	i1->second = 111;
	std::cout<<i1->second<<std::endl;

	// ft::pair<int, int> a(1, 11);
	// ft::pair<int, int> b(2, 12);
	// ft::pair<int, int> c(3, 13);
	// ft::pair<int, int> d(4, 14);
	// ft::pair<int, int> f(5, 15);
	// ft::pair<int, int> g(6, 16);
	// ft::pair<int, int> h(7, 17);
	// ft::pair<int, int> i(8, 18);
	// ft::pair<int, int> j(9, 19);

	// ft::map<int, int> t;

	// std::cout<<t.insert(a).first->first;
	// std::cout<<t.insert(b).first->first;
	// std::cout<<t.insert(c).first->first;
	// std::cout<<t.insert(d).first->first;
	// std::cout<<t.insert(f).first->first;
	// std::cout<<t.insert(g).first->first;
	// std::cout<<t.insert(h).first->first;
	// std::cout<<t.insert(i).first->first;
	// std::cout<<t.insert(j).first->first;

	// std::cout<<std::endl;

	// std::cout<<"size: "<<t.size()<<std::endl;

	// // ft::map<int, int>::reverse_iterator beg = t.rbegin();
	// // ft::map<int, int>::reverse_iterator beg1 = t.rbegin();
	// ft::map<int, int>::reverse_iterator enn = t.rend();
	// --(--enn);
	// std::cout<<"enn: "<<enn->first<<std::endl;
	
	
	// // while (beg != enn)
	// // {
	// // 	std::cout<<beg->first;
	// // 	beg++;
	// // }
	// // std::cout<<std::endl;

	// // t.at(3) = 33;
	// // std::cout<<"at: "<<t.at(3)<<std::endl;

	// // // t.erase(3);
	// // t.erase(4);

	// // std::cout<<"size: "<<t.size()<<std::endl;
	// // std::cout<<"max_size: "<<t.max_size()<<std::endl;

	// // while (beg1 != enn)
	// // {
	// // 	std::cout<<beg1->first;
	// // 	beg1++;
	// // }
	// // std::cout<<std::endl;



	// std::cout<<"end"<<std::endl;

	// std::pair<int, int> a1(1, 11);
	// std::pair<int, int> b1(2, 12);
	// std::pair<int, int> c1(3, 13);
	// std::pair<int, int> d1(4, 14);
	// std::pair<int, int> f1(5, 15);
	// std::pair<int, int> g1(6, 16);
	// std::pair<int, int> h1(7, 17);
	// std::pair<int, int> i1(8, 18);
	// std::pair<int, int> j1(9, 19);

	// std::map<int, int> m;

	// std::cout<<m.insert(a1).first->first;
	// std::cout<<m.insert(b1).first->first;
	// std::cout<<m.insert(c1).first->first;
	// std::cout<<m.insert(d1).first->first;
	// std::cout<<m.insert(f1).first->first;
	// std::cout<<m.insert(g1).first->first;
	// std::cout<<m.insert(h1).first->first;
	// std::cout<<m.insert(i1).first->first;
	// std::cout<<m.insert(j1).first->first;

	// std::cout<<std::endl;

	// // std::cout<<"size: "<<m.size()<<std::endl;

	// // std::map<int, int>::reverse_iterator m1 = m.rbegin();
	// // std::map<int, int>::reverse_iterator m2 = m.rbegin();
	// std::map<int, int>::reverse_iterator m3 = m.rend();

	// --(--m3);
	// std::cout<<"m3: "<<m3->first<<std::endl;

	// // while (m1 != m3)
	// // {
	// // 	std::cout<<m1->first;
	// // 	m1++;
	// // }
	// // std::cout<<std::endl;

	// // m.at(3) = 33;
	// // std::cout<<"at: "<<m.at(3)<<std::endl;

	// // // m.erase(3);
	// // m.erase(4);

	// // std::cout<<"size: "<<m.size()<<std::endl;
	// // std::cout<<"max_size: "<<m.max_size()<<std::endl;

	// // while (m2 != m3)
	// // {
	// // 	std::cout<<m2->first;
	// // 	m2++;
	// // }
	// // std::cout<<std::endl;

	// // ft::map<std::string, std::string> cc;
	// // std::cout<<"maxCC: "<<cc.max_size()<<std::endl;

	// // std::map<std::string, std::string> cc1;
	// // std::cout<<"SmaxCC: "<<cc1.max_size()<<std::endl;

	return (0);
}