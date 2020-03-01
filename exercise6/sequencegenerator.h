#ifndef SEQ_GEN_H
#define SEQ_GEN_H

template <typename T>
class SequenceGenerator {
private:
    T begin;
    T jump;
public:
    const static unsigned int DEFAULT_JUMP = 1;
    SequenceGenerator(T begin, T jump): begin(begin), jump(jump){};
    SequenceGenerator(T begin): begin(begin), jump(DEFAULT_JUMP){};
    SequenceGenerator(): begin(DEFAULT_JUMP - 1), jump(DEFAULT_JUMP){};

    T operator()(){
        T ret = begin;
        begin += jump;
        return ret;
    }
};

#endif
