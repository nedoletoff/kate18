#pragma once
#include <iostream>
#include <set>

class mySet : public std::set<int>{
	public:
		mySet combine(const mySet& a) {
			mySet y;
			y = *this;
			clear();
			std::set<int> c = a;	
			for (auto ita = y.begin(); ita != y.end(); ++ita) {
				for(auto itb = c.begin(); itb != c.end(); ++itb) {
					if (*ita == *itb){
						insert(*itb);
					}
				}
			}
			return *this;
		}
		mySet intersect(const mySet& a) {
			std::set<int> c = a;
			merge(c);
			return *this;
		}

		mySet minus(const mySet& a) {
			mySet r;
			r = *this;
			r.combine(a);
			intersect(a);
			for (auto e : r)
				erase(e);
			return *this;
		}	

};
