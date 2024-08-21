#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


int frame_size = 3;
std::vector<int> physical_memory;
std::queue<int> page_queue;
int page_faults = 0;
int Access_Memory(int page_number){
    if(std::find(physical_memory.begin(), physical_memory.end(), page_number) != physical_memory.end()){
        return 1;
    }
    else{
        page_faults++;

        if(physical_memory.size() < frame_size){
            physical_memory.push_back(page_number);
            page_queue.push(page_number);
        }else{
            int page_to_remove = page_queue.front();
            page_queue.pop();
            std::vector<int>::iterator it = std::find(physical_memory.begin(), physical_memory.end(), page_to_remove);
            *it = page_number;

            page_queue.push(page_number);
        }
        return 0;
    }
}
int main(){
    std::cout << "FIFO.cc"<< std::endl;

    std::vector<int> access_sequence = {7,0,1,2,0,3,0,4,2,3,0,3,2,1};
    for(int i = 0; i < access_sequence.size(); i++){
        Access_Memory(access_sequence[i]);
        std::cout << "Accessing page " << access_sequence[i] << std::endl;
        for(int j = 0; j < physical_memory.size(); j++){
            std::cout << physical_memory[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Page faults: " << page_faults << std::endl;

    return 0;
}