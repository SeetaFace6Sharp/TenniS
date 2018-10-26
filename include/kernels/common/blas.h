//
// Created by seeta on 2018/7/19.
//

#ifndef TENSORSTACK_KERNELS_COMMON_BLAS_H
#define TENSORSTACK_KERNELS_COMMON_BLAS_H

// #include <OpenBLAS/cblas.h>

namespace ts {
    namespace blas {
        enum Order {
            RowMajor = 101,
            ColMajor = 102
        };
        enum Transpose {
            NoTrans = 111,
            Trans = 112
        };
    }
}


#endif //TENSORSTACK_KERNELS_COMMON_BLAS_H