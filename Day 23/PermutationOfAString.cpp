#include <bits/stdc++.h>
using namespace std;

void permute(string string, int index, vector<vector<int>> &result){

    //base case
    //if the index is equal to the length of the string then we have reached the end of the string
    if(index == string.length() - 1){
        vector<int> temp;
        for(int i = 0; i < string.length(); i++){
            temp.push_back(string[i]);
        }
        result.push_back(temp);
        return;
    }

    for(int i = index; i < string.length(); i++){
        //now swapping the string
        swap(string[index], string[i]);
        //now calling the permute function again where index is increased by 1 so that we can get the next permutation
        permute(string, index + 1, result);
        //now swapping back the string so that we can get the original string
        //we need to swap back the string because we are passing the same string in the next function call
        //this is to avoid the repetition of the string
        //below is the backtracking step
        swap(string[index], string[i]);
    }
}

vector<vector<int>> permutation(string string){
    vector<vector<int>> result;
    int index = 0;
    permute(string, index, result);
    return result;
}
 
int main() {
    string string = "ABC";
    vector<vector<int>> result = permutation(string);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            
            cout << (char)result[i][j];
        }
        cout << endl;
    }

    return 0;
}

/* How above code works
1. We are passing the string, index and the result vector in the permute function
2. In the permute function we are checking if the index is equal to the length of the string - 1
3. If the index is equal to the length of the string - 1 then we have reached the end of the string
4. Now we are pushing the string in the result vector
5. Now we are swapping the string
6. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
7. Now we are swapping back the string so that we can get the original string
8. We need to swap back the string because we are passing the same string in the next function call
9. This is to avoid the repetition of the string
10. Now we are returning the result vector.
*/

/*Working example "ABC"
1. First the string ABC is passed in the permutation function
2. Now the string ABC, index 0 and the result vector is passed in the permute function
3. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
4. Now we are swapping the string i.e. A is swapped with A(1st iteration)
5. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
6. Now the string ABC, index 1 and the result vector is passed in the permute function
7. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
8. Now we are swapping the string i.e. B is swapped with B(2nd iteration)
9. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
10. Now the string ABC, index 2 and the result vector is passed in the permute function
11. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector
12. Now we are swapping the string i.e. C is swapped with C(3rd iteration)
13. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
14. Now the string ABC, index 1 and the result vector is passed in the permute function
15. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
16. Now we are swapping the string i.e. B is swapped with C(4th iteration)
17. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
18. Now the string ABC, index 2 and the result vector is passed in the permute function
19. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector hence we get the permutation ABC
20. Now we are swapping the string i.e. C is swapped with B(5th iteration)
21. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
22. Now the string ABC, index 1 and the result vector is passed in the permute function
23. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
24. Now we are swapping the string i.e. B is swapped with B(6th iteration)
25. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
26. Now the string ABC, index 2 and the result vector is passed in the permute function
27. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector hence we get the permutation ACB
28. Now we are swapping the string i.e. C is swapped with A(7th iteration)
29. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
30. Now the string ABC, index 1 and the result vector is passed in the permute function
31. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector 
32. Now we are swapping the string i.e. B is swapped with A(8th iteration)
33. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
34. Now the string ABC, index 2 and the result vector is passed in the permute function
35. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector hence we get the permutation BAC
36. Now we are swapping the string i.e. C is swapped with A(9th iteration)
37. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
38. Now the string ABC, index 0 and the result vector is passed in the permute function
39. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
40. Now we are swapping the string i.e. A is swapped with A(10th iteration)
41. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
42. Now the string ABC, index 1 and the result vector is passed in the permute function
43. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
44. Now we are swapping the string i.e. B is swapped with B(11th iteration)
45. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
46. Now the string ABC, index 2 and the result vector is passed in the permute function
47. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector hence we get the permutation BCA
48. Now we are swapping the string i.e. C is swapped with B(12th iteration)
49. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
50. Now the string ABC, index 1 and the result vector is passed in the permute function
51. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
52. Now we are swapping the string i.e. B is swapped with C(13th iteration)
53. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
54. Now the string ABC, index 2 and the result vector is passed in the permute function
55. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector hence we get the permutation CAB
56. Now we are swapping the string i.e. C is swapped with C(14th iteration)
57. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
58. Now the string ABC, index 0 and the result vector is passed in the permute function
59. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
60. Now we are swapping the string i.e. A is swapped with B(15th iteration)
61. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
62. Now the string ABC, index 1 and the result vector is passed in the permute function
63. Now the index is not equal to the length of the string - 1 so we are not pushing the string in the result vector
64. Now we are swapping the string i.e. B is swapped with A(16th iteration)
65. Now we are calling the permute function again where index is increased by 1 so that we can get the next permutation
66. Now the string ABC, index 2 and the result vector is passed in the permute function
67. Now the index is equal to the length of the string - 1 so we are pushing the string in the result vector hence we get the permutation CBA
68. Now we are swapping the string i.e. C is swapped with A(17th iteration)
69. As a result we get all the permutations of the string ABC.


*/