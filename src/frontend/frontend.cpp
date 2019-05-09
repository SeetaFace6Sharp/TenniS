//
// Created by kier on 2019/3/27.
//

#include "frontend/frontend.h"

#include "module/menu.h"
#include "backend/name.h"
#include "core/tensor_builder.h"

namespace ts {
    namespace frontend {
        NodeOrTensor::NodeOrTensor(const Node &node)
            : m_node(node) {}

        NodeOrTensor::NodeOrTensor(const Tensor &tensor)
                : m_node(bubble::data("", tensor)) {}

        NodeOrTensor::NodeOrTensor(const Tensor &tensor, const char *device)
                : m_node(bubble::data("", tensor, device)) {}

        NodeOrTensor::NodeOrTensor(const Tensor &tensor, const DeviceType &device)
                : m_node(bubble::data("", tensor, device)) {}

        NodeOrTensor::NodeOrTensor(const Tensor &tensor, const MemoryDevice &device)
                : m_node(bubble::data("", tensor, device.type())) {}

        NodeOrTensor::operator Node() const {
            return m_node;
        }

        Node pad(const std::string &name, const NodeOrTensor &x, const NodeOrTensor &padding,
                           float padding_value) {
            return symbol::pad(name, x, padding, padding_value);
        }

        Node pad(const std::string &name, const NodeOrTensor &x, const std::vector<DimPadding> &padding, float padding_value) {
            TS_AUTO_CHECK(!padding.empty());
            auto padding_tensor = tensor::build(INT32, {int(padding.size()), 2}, &padding[0].first);
            return pad(name, x, {padding_tensor, CPU}, padding_value);
        }

        Node resize2d(const std::string &name, const NodeOrTensor &x, const NodeOrTensor &size, desc::ResizeType type) {
            return symbol::resize2d(name, x, size, type);
        }

        Node resize2d(const std::string &name, const NodeOrTensor &x, const std::vector<int32_t> &size,
                                desc::ResizeType type) {
            TS_AUTO_CHECK(!size.empty());
            auto size_tensor = tensor::build(INT32, size.size(), size.data());
            return resize2d(name, x, {size_tensor, CPU}, type);
        }

        Node add(const std::string &name, const NodeOrTensor &lhs, const NodeOrTensor &rhs) {
            return symbol::add(name, lhs, rhs);
        }

        Node sub(const std::string &name, const NodeOrTensor &lhs, const NodeOrTensor &rhs) {
            return symbol::sub(name, lhs, rhs);
        }

        Node mul(const std::string &name, const NodeOrTensor &lhs, const NodeOrTensor &rhs) {
            return symbol::mul(name, lhs, rhs);
        }

        Node div(const std::string &name, const NodeOrTensor &lhs, const NodeOrTensor &rhs) {
            return symbol::div(name, lhs, rhs);
        }
    }
}