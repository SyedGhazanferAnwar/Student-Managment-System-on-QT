#ifndef MARKS_H
#define MARKS_H


class marks
{
    float totalMarks;
    float mid1;
    float mid2;
    float final;
    float sessionals;

public:;
    marks();
    float getTM();
    float getMid1();
    float getMid2();
    float getSessionals();
    float getFinal();
    void setMid1(float);
    void setMid2(float);
    void setSessionls(float);
    void setFinal(float);
};

#endif // MARKS_H
