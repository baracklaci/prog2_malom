#ifndef vektor
#define vektor

template<typename T>
class SzebiVektor{
    T *adat;
    size_t meret;
    size_t foglalt;
    void novel(){
        T *tmp = new T[foglalt*2];
        for (size_t i = 0; i < foglalt; i++){
            tmp[i] = adat[i];
        }
        foglalt *= 2;
        delete[] adat;
        adat = tmp;
    }
public:
    SzebiVektor(): meret(0){
        adat = new T[20];
        foglalt = 20;
    }
    void pushback(T t){
        if (meret == foglalt)
            novel();
        adat[meret++] = t;
    }
    void popback(){
        meret--;
    }
    T& operator[](size_t s){
        return adat[s];
    }
    const T& operator[](size_t s) const{
        return adat[s];
    }
    size_t size() const{
        return meret;
    }
    ~SzebiVektor(){
        delete[] adat;
    }
};

#endif // vektor
