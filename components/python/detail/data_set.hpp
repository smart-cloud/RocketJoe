#pragma once

#include <deque>

#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <detail/forward.hpp>
#include <nlohmann/json.hpp>

namespace components { namespace python { namespace detail {

    using namespace pybind11::literals;
    namespace py = pybind11;

    class BOOST_SYMBOL_VISIBLE data_set : public boost::intrusive_ref_counter<data_set> {
    public:
        data_set(const data_set&) = delete;

        data_set& operator=(const data_set&) = delete;

        data_set(const py::object&, context*);

        data_set();

        virtual ~data_set() = default;

        auto map(py::function, bool preservesPartitioning = false) -> boost::intrusive_ptr<pipelien_data_set>;

        auto reduce_by_key(py::function, bool preservesPartitioning = false) -> boost::intrusive_ptr<pipelien_data_set>;

        auto flat_map(py::function, bool preservesPartitioning = false) -> boost::intrusive_ptr<pipelien_data_set>;

        auto collect() -> py::list;

        auto map_partitions_with_index(py::function, bool preservesPartitioning = false) -> boost::intrusive_ptr<pipelien_data_set>;

        auto map_partitions(py::function, bool preservesPartitioning = false) -> boost::intrusive_ptr<pipelien_data_set>;

        auto ctx() -> context*;

    protected:
        py::object collection_;
        context* ctx_;

    private:
        ///bool serializable_;
        nlohmann::json json_data_set_;
    };

    class BOOST_SYMBOL_VISIBLE pipelien_data_set final : public data_set {
    public:
        pipelien_data_set(data_set*, py::function, bool);

    private:
        py::function f_;
    };

}}} // namespace components::python::detail
