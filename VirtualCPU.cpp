#include "VirtualCPU.hpp"
VirtualCPU::VirtualCPU(const MutantStack<IOperand *> * mutantStack) {
  _ptr1.push_back(&VirtualCPU::push);
  _ptr1.push_back(&VirtualCPU::assert);
  _ptr0.push_back(&VirtualCPU::pop);
  _ptr0.push_back(&VirtualCPU::dump);
  _ptr0.push_back(&VirtualCPU::add);
  _ptr0.push_back(&VirtualCPU::sub);
  _ptr0.push_back(&VirtualCPU::mul);
  _ptr0.push_back(&VirtualCPU::div);
  _ptr0.push_back(&VirtualCPU::mod);
  _ptr0.push_back(&VirtualCPU::print);
  _ptr0.push_back(&VirtualCPU::exit);
  
}

VirtualCPU::~VirtualCPU() {
  
}

void            VirtualCPU::push(IOperand *elem) {
  _mutantStack->push(elem);
}

void            VirtualCPU::assert(IOperand *elem) {

}

void            VirtualCPU::pop() {
  _mutantStack->pop();
}

void            VirtualCPU::dump() {
}

void            VirtualCPU::add() {
}

void            VirtualCPU::sub() {
}

void            VirtualCPU::mul() {
}

void            VirtualCPU::div() {
}

void            VirtualCPU::mod() {
}

void            VirtualCPU::print() {
}

void            VirtualCPU::exit() {
}

IOperand *	VirtualCPU::createOperand(eOperandType type, const std::string & value) {

}

IOperand *	VirtualCPU::createInt8(const std::string & value) {
}

IOperand *	VirtualCPU::createInt16(const std::string & value) {

}

IOperand *	VirtualCPU::createInt32(const std::string & value) {

}

IOperand *	VirtualCPU::createFloat(const std::string & value) {

}

IOperand *	VirtualCPU::createDouble(const std::string & value) {

}


