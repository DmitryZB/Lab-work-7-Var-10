#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct TwoDVec{
    int x;
    int y;
};

struct ThreeDVec{
    int x0;
    int y0;
    int z0;
    int x;
    int y;
    int z;
};

void VecOut(vector<TwoDVec> v){
    for(int i = 0; i < v.size(); ++i ){
        cout << i+1 << " vector: {" << v[i].x << ", " << v[i].y << '}' << endl;
    }
}

//--------------------------MergeSort----------------------------------------------------
/*
vector<TwoDVec> Merge(vector<TwoDVec> v1, vector<TwoDVec> v2)
{
    unsigned long len = v1.size() + v2.size();
    vector<TwoDVec> vRes(len);
    int it1 = 0;
    int it2 = 0;
    for (int i = 0; i < len; ++i){
        if(v1[it1].x < v2[it2].x){
            vRes[i] = v1[it1];
            it1++;
            if (it1 > (v1.size()-1)){
                while(v2.size()>=it2){
                    vRes[it1+it2] = v2[it2];
                    it2++;
                }
                break;
            }
        }
        else if (v1[it1].x == v2[it2].x){
            if (v1[it1].y <= v2[it2].y){
                vRes[i] = v1[it1];
                it1++;
            }
            else{
                vRes[i] = v1[it2];
                it2++;
            }
        }
            else{
                vRes[i] = v2[it2];
                it2++;
                if (it2 > (v2.size()-1)){
                    while(v1.size()>=it1){
                        vRes[it1+it2] = v1[it1];
                        it1++;
                    }
                    break;
                }
            }
    }
    return vRes;
}

vector<TwoDVec> SwapSort(vector<TwoDVec> v)
{
    if ((v.size() == 2) and (v[0].x > v[1].x)){
        swap(v[0], v[1]);
    }
    else if (v[0].x == v[1].x){
        if (v[0].y > v[1].y){
            swap(v[0], v[1]);
        }
    }
    return v;
}

vector<TwoDVec> MergeSort(vector<TwoDVec> v) //Main sorting function
{
    vector<TwoDVec> vRes;
    unsigned long half;
    
    if(v.size() == 1){
        return v;
    }
    
    if(v.size() == 2){
        return SwapSort(v);
    }
    
    if((v.size() % 2) == 0){
        half = v.size()/2;
    }
    
    else{
        half = v.size()/2 + 1;
    }
    
    vector<TwoDVec> v1(half);
    for(int i = 0; i < half; ++i){
        v1[i] = v[i];
    }
    
    vector<TwoDVec> v2(v.size() - half);
    for(int i = 0; i < (v.size() - half); ++i){
        v2[i] = v[i + half];
    }
     
    if(v1.size() > 2 && v2.size() > 2){
        vRes = Merge(MergeSort(v1), MergeSort(v2));
        
    }
    
    else if(v1.size() > 2 && v2.size() <= 2){
        vRes = Merge(SwapSort(v2), MergeSort(v1));
    }
   
    else{
        vRes = Merge(SwapSort(v1), SwapSort(v2));
    }

    return vRes;
}
*/
//-------------------------End of MergeSort-----------------------------------------------

vector<int> operator+(vector<int> vec1, vector<int> vec2){      //summ of vectors
    const unsigned long x = max(vec1.size(), vec2.size());
    vector<int> vRes(x);
    for (int i = 0; i < x; ++i){
        vRes[i] = vec1[i] + vec2[i];
        if (i >= vec1.size() && i < vec2.size()){
            vRes[i] = vec2[i];
        }
        if (i >= vec2.size() && i < vec1.size()){
            vRes[i] = vec1[i];
        }
    }
    return vRes;
}

unsigned long operator*(vector<int> vec1, vector<int> vec2){        //scalar multiply
    const unsigned long x = min(vec1.size(), vec2.size());
    unsigned long res = 0;
    for (int i = 0; i < x; ++i){
        res += vec1[i] * vec2[i];
    }
    return res;
}

bool operator<(TwoDVec vec1, TwoDVec vec2){        //overload operator '<' for function sort
    if(vec1.x == vec2.x){
        if(vec1.y == vec2.y){
            return false;                   //don't do any changes
        }
        else{
            return vec1.y < vec2.y;         //sort will change vec1 and vec2
        }
    }
    else{
        return vec1.x < vec2.x;             //sort will change vec1 and vec2
    }
}

vector<int> Cinv(unsigned long x){      //cin overload
    vector<int> vRes(x);
    unsigned long i = x;
    while(i > 0){
        cout << "Enter " << x - i + 1 << " element: ";
        cin >> vRes[x - i];
        i--;
    }
    return vRes;
}

void Couterv(vector<int> v){        //cout overload
    cout << '{';
    for (int i = 0; i<v.size()-1; ++i){
        cout << v[i] << "; ";
    }
    
    cout << v[v.size()-1] << '}' << endl;
}




int main() {
    std::random_device rd;
    
    //TASK №1
    //ThreeDVec vect;
    
    //TASK №2
    unsigned long x;
    cout << "Enter size of first nD-vector: ";
    cin >> x;
    vector<int> v1(x);
    v1 = Cinv(x);
    cout<< "Your vector: ";
    Couterv(v1);
    cout << endl;
    unsigned long y;
    cout << "Enter size of second nD-vector: ";
    cin >> y;
    vector<int> v2(y);
    v2 = Cinv(y);
    cout << endl;
    cout << "Vector summ: ";
    Couterv(v1+v2);
    cout << "Scalar multiply of vectors: "<< v1*v2 << endl;
    cout << endl;
    
    //TASK №3
    unsigned long z;
    cout << "Enter count of vectors: ";
    cin >> z;
    TwoDVec vc;
    vector<TwoDVec> vect(z);
    for (unsigned long i = 0; i < z; ++i){
        vc.x = rd() % 2000 - 1000;
        vc.y = rd() % 2000 - 1000;
        vect[i] = vc;
    }
    VecOut(vect);
    
    //TASK №4
    //vector<TwoDVec> vect_sorted = MergeSort(vect);
    sort(vect.begin(), vect.end());
    cout << "\nSorted list of vectors:" << endl;
    VecOut(vect);
    
    return 0;
}
