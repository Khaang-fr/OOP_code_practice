#include <iostream>
using namespace std;
#include "SoPhuc.h"
SoPhuc SoPhuc::operator+(const SoPhuc& b) const {
    SoPhuc result;
    result.thuc = this->thuc + b.thuc;
    result.ao = this->ao + b.ao;
    return result;
}
SoPhuc SoPhuc::operator-(SoPhuc b) {
    SoPhuc result;
    result.thuc = this->thuc - b.thuc;
    result.ao = this->ao - b.ao;
    return result;
}
SoPhuc SoPhuc::operator*(SoPhuc b) {
    SoPhuc result;
    result.thuc = this->thuc * b.thuc - this->ao * b.ao;
    result.ao = this->thuc * b.ao + this->ao * b.thuc;
    return result;
}
SoPhuc SoPhuc::operator/(SoPhuc b) {
    SoPhuc result;
    float denominator = b.thuc * b.thuc + b.ao * b.ao;
    result.thuc = (this->thuc * b.thuc + this->ao * b.ao) / denominator;
    result.ao = (this->ao * b.thuc - this->thuc * b.ao) / denominator;
    return result;
}
bool SoPhuc::operator==(const SoPhuc& b) const {
    return this->thuc == b.thuc && this->ao == b.ao;
}
bool SoPhuc::operator!=(const SoPhuc& b) const {
    return !(*this == b);
}
