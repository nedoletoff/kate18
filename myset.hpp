#pragma once
#include <iostream>
#include <set>

class mySet : public std::set<int>{
	public:
		mySet combine(const mySet& a) {
			mySet c;
                        for (auto e1 : a)
                                for (auto e2 : *this)
                                        if (e1 == e2)
                                                c.insert(e1);
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
