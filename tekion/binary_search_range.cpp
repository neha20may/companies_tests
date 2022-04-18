//
// Created by neha2 on 12-04-2022.
//
#include <iostream>
/**
 * sorted array, find frequency of some number k,
 * Input: array, k is the input,
 * k might /not be present in array
 * array size:
 * array of integers.
 *
 *
 *
 *  freq: array -----> hashmap element, freq)
 *  Time complexity: TRaverse: O(N)
 *  sorted; binary search
 *  *11111 222222333334444
 *  upper-lower  =O(logn)
 *
 *
 *  lower==>
 *  1. array--> binarsyS(ar, k)==> some index;
 * index--> left ====> (!k)=> worst case O(n)
 *  *1^1
 * => binary search()==index
 *  (arr__)==Null
 * 1111 2222222233333 44^44 ==log n
 * 1111 2222222233333 44===  log n
 * 1111 2222222233333 4==log n
 *
 * 444444444444444^44444444444444
 *
 * log(n) + log(n/2)+ log(n/4)----log(2) = O(log n)
 * log(n/2^i)
 *
 * Left : 1111 22^22
 * 1111 2^2
 * 1111 2 ==> required answer
 * 1111==> null
 *  freq === f*logN ==(n logn );
 *  approach 1:
 *  approach 2: remove key
 *  approach 3: BST/SET; keys are nt unique ?? to create it, traverse array once==>O(N)
 *  approach  4:  * solution
 * @return
 */
#include <bits/stdc++.h>

using namespace std;

vector<int>::iterator b_search(vector<int>::iterator begin, vector<int>::iterator end, int key) {
    //base cases
    if (begin >= end) {
        return begin;
    }
//    cout << " begin " << *begin << " end " << *(end - 1) << " ";
    auto mid = begin + (end - begin) / 2;
//    cout << "mid  " << *mid << endl;
    if (key == *mid) {
//        int pos = distance(begin, mid);
        return mid;
    } else {
        if (key < *mid) {
            auto l=b_search(begin, mid, key);
            return l;
        } else {
            auto  r= b_search(mid + 1, end, key);
            return r;
        }
    }
}/**
 * (b)1 (e)2 <---
 * @param begin
 * @param end
 * @param key
 * @return
 */
////111
void left_b_search(vector<int>::iterator begin, vector<int>::iterator end,
                   vector<int> &input, int key, int &ans) {
    //begin --> 1 end--> 2
    //base case  array has one element (1)
    //b=0
    //e=2
    if (end == begin + 1) {
        int element = *begin;
        if (element == key) {
            ans= distance(begin, begin); //==> pos
            return;
        } else {
            ans = -1;
            return;
        }
    }
    auto pos = b_search(begin, end, key);
    if (pos == end) {
        int left_range_index;
        if(*pos==key){
            left_range_index = distance(begin, pos-1);
        }
        else{
            left_range_index= distance(input.begin(), pos);
        }
        ans = left_range_index;
        return;
    }
    auto pos_iter = input.begin() + distance(input.begin(), pos);
    //pos iter=3
    left_b_search(input.begin(), pos_iter - 1, input, key, ans);
};

//int right_b_search(vector<int> ::iterator begin, vector<int> :: iterator end, int key){
//    return b_search( begin, end, key);
//}
int main() {
    //Input reader
    vector<int> input = {1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 4};
    copy(input.begin(), input.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
    int key = 4;
    auto pos = b_search(input.begin(), input.end(), key);
    int pos_index=pos-input.begin();
    cout << "key " << key << " in array pos =" << distance(input.begin(), pos) << endl;
    //***** ........ key(2) .....pos......key(4)   *****//
    auto pos_iter=input.begin()+ distance(input.begin(), pos);
    int ans=-1;
    left_b_search(input.begin(), pos_iter-1, input, key,ans);
    cout<<"left range  "<<ans<<endl;
//    int right_pos=right_b_search(pos_iter+1, input.end(), key);
//    int freq=right_pos-left_pos+1;
//    return pos;
}

