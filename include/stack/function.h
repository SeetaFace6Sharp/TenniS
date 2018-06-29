//
// Created by seeta on 2018/5/19.
//

#ifndef TENSORSTACK_STACK_FUNCTION_H
#define TENSORSTACK_STACK_FUNCTION_H

#include <map>
#include <string>
#include <tensor/tensor.h>

namespace ts {
    class Stack;

    class Function {
    public:
        using self = Function;    ///< self class
        using shared = std::shared_ptr<self>;  ///< smart pointer

        // work on tensor stack, same as call
        virtual int run(Stack &stack) = 0;

        // infer output size by input size, only for size allocate
        virtual int infer(Stack &stack, std::vector<Tensor::Prototype> &output) = 0;

        void set(const std::string &param, const Tensor &value);

        Tensor &get(const std::string &param);

        const Tensor &get(const std::string &param) const;

        void clear(const std::string &param);

        void clear_params();

    private:
        std::map<std::string, Tensor> m_params;
    };

}


#endif //TENSORSTACK_STACK_FUNCTION_H