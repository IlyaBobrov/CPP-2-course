#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;


#include <vector>
class Set {
 public:
    Set Union(const Set& oth) const {
        Set vec_buf;
        for (unsigned int i = 0; i < oth.Data().size() + vec.size(); i++)
            if (i < oth.Data().size())
                vec_buf.Add(oth.Data()[i]);
            else
                vec_buf.Add(vec[i - oth.Data().size()]);
        return vec_buf;
    }

    Set Intersection(const Set& oth) const {
        Set vec_buf;
        for (unsigned int i = 0; i < oth.Data().size(); i++)
            for (unsigned int j = 0; j < vec.size(); j++)
                if (oth.Data()[i] == vec[j])
                    vec_buf.Add(vec[i]);
        return vec_buf;
    }

    Set Difference(const Set& oth) const {
        Set vec_buf(vec);
        for (unsigned int i = 0; i < oth.Data().size(); i++)
            for (unsigned int j = 0; j < vec.size(); j++)
                if (oth.Data()[i] == vec[j])
                    vec_buf.Remove(oth.Data()[i]);
        return vec_buf;
    }

    Set SymmetricDifference(const Set& oth) const {
        Set vec_buf;
        for (unsigned int i = 0; i < oth.Data().size() + vec.size(); i++)
            if (i < oth.Data().size()) {
                if (!(*this).Contains(oth.Data()[i]))
                    vec_buf.Add(oth.Data()[i]);
            } else {
                if (!oth.Contains(vec[i - oth.Data().size()]))
                    vec_buf.Add(vec[i - oth.Data().size()]);
            }
        return vec_buf;
    }

    Set() {}

    explicit Set(const std::vector<int64_t>& oth) {
        for (unsigned int i = 0; i < oth.size() ; ++i)
            (*this).Add(oth[i]);
    }

    void Add(int64_t value) {
        if (!(*this).Contains(value))
            vec.push_back(value);
    }

    void Remove(int64_t value) {
        int pos = 0;
        for (unsigned int i = 0; i < vec.size(); i++)
            if (vec[i] == value) {
                pos = i;
                continue;
            }
        for (unsigned int i = pos; i < vec.size() - 1; i++) {
            vec[i] = vec[i + 1];
        }
        vec.pop_back();
    }

    bool Contains(int64_t value) const {
        for (unsigned int i = 0; i < vec.size(); i++)
            if (vec[i] == value)
                return true;
        return false;
    }

    std::vector<int64_t> Data() const {
        return vec;
    }

 private:
    std::vector<int64_t> vec;
};
