#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct TwoDVec{
    float x;
    float y;
};

struct ThreeDVec{
    float x;
    float y;
    float z;
};

void VecOut(vector<TwoDVec> v){
    for(int i = 0; i < v.size(); ++i ){
        cout << i+1 << " vector: {" << v[i].x << ", " << v[i].y << '}' << endl;
    }
}

ThreeDVec operator+(ThreeDVec vec1, ThreeDVec vec2){      //summ of vectors
    ThreeDVec vRes;
    vRes.x = vec1.x + vec2.x;
    vRes.y = vec1.y + vec2.y;
    vRes.z = vec1.z + vec2.z;
    return vRes;
}

double operator*(ThreeDVec vec1, ThreeDVec vec2){        //scalar multiply
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

bool operator<(TwoDVec vec1, TwoDVec vec2){         //overload operator '<' for function sort
    if(vec1.x == vec2.x){
        if(vec1.y == vec2.y){
            return false;                           //don't do any changes
        }
        else{
            return vec1.y < vec2.y;                 //sort will change vec1 and vec2
        }
    }
    else{
        return vec1.x < vec2.x;                     //sort will change vec1 and vec2
    }
}

ThreeDVec Cinv(){                                   //cin overload
    ThreeDVec vRes;
    cin >> vRes.x >> vRes.y >> vRes.z;
    return vRes;
}

void Couterv(ThreeDVec v){                          //cout overload
    cout << '{' << v.x << ' ' << v.y << ' ' << v.z << '}';
}

int main() {
    std::random_device rd;
    
    //TASK №1
    //ThreeDVec vect;
    
    //TASK №2
    ThreeDVec v1;
    cout<< "Enter your 3D-vector: ";
    v1 = Cinv();
    cout<< "Your vector: ";
    Couterv(v1);
    cout << endl;
    ThreeDVec v2;
    cout<< "Enter your 3D-vector: ";
    v2 = Cinv();
    cout << endl;
    cout << "Vector summ: ";
    Couterv(v1+v2);
    cout << endl;
    cout << "Scalar multiply of vectors: "<< v1*v2 << endl;
    cout << endl;
    
    //TASK №3
    unsigned long z;
    cout << "Enter count of vectors: ";
    cin >> z;
    TwoDVec vc;
    vector<TwoDVec> vect(z);
    for (unsigned long i = 0; i < z; ++i){
        vc.x = rd();
        vc.y = rd();
        vect[i] = vc;
    }
    VecOut(vect);
    
    //TASK №4
    sort(vect.begin(), vect.end());
    cout << "\nSorted list of vectors:" << endl;
    VecOut(vect);
    
    return 0;
}
