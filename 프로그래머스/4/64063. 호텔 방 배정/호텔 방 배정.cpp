#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;

long long find_room(long long n){
    if(!room[n]) return n;
    else return room[n] = find_room(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    for(auto &want : room_number){
        long long assigned = find_room(want);
        want = assigned;
        room[assigned] = assigned+1;
    }
    return room_number;
}