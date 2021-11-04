//
// Created by undefined on 03.11.2021.
//

#include "TransactionData.h"

TransactionData::TransactionData(double amount, const string &senderKey, const string &receiverKey, time_t timestamp)
        : amount(amount), senderKey(senderKey), receiverKey(receiverKey), timestamp(timestamp) {}
