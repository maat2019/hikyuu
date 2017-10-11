/*
 * KDataDriver.cpp
 *
 *  Created on: 2014年9月2日
 *      Author: fasiondog
 */

#include "kdata/tdx/TdxKDataDriverImp.h"
#include "../StockManager.h"
#include "KDataDriver.h"

namespace hku {

KDataDriver::KDataDriver(const string& name): m_name(name) {
    boost::to_upper(m_name);
}


void KDataDriver::
loadKData(const string& market, const string& code, KQuery::KType kType,
        size_t start_ix, size_t end_ix, KRecordList* out_buffer) {
}

size_t KDataDriver::
getCount(const string& market, const string& code, KQuery::KType kType) {
    return 0;
}

bool KDataDriver::
getIndexRangeByDate(const string& market, const string& code,
        const KQuery& query, size_t& out_start, size_t& out_end) {
    return false;
}

KRecord KDataDriver::
getKRecord(const string& market, const string& code,
        size_t pos, KQuery::KType kType) {
    return Null<KRecord>();
}

bool KDataDriver::checkType() {
    bool result = false;
    try {
        string type = getParam<string>("type");
        boost::to_upper(type);
        if (type == m_name) {
            result = true;
        } else {
            result = false;
            HKU_WARN("Type of driver mismatch! ("
                    << type << " != " << m_name << ") "
                    << "[KDataDriver::checkType]");
        }

    } catch(...) {
        result = false;
        HKU_ERROR("Can't get type of driver! [KDataDriver::checkType]");
    }

    return result;
}

bool KDataDriver::init(const Parameter& params) {
    if (m_params == params) {
        return true;
    }

    m_params = params;
    if (!checkType()) {
        return false;
    }

    return _init();
}

} /* namespace hku */



