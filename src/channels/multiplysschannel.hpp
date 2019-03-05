/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2018-2019 Frank Stettner <frank-stettner@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHANNELS_MULTIPLYSSCHANNEL_HPP
#define CHANNELS_MULTIPLYSSCHANNEL_HPP

#include <memory>
#include <mutex>
#include <set>

#include <QObject>

#include "src/channels/basechannel.hpp"
#include "src/channels/userchannel.hpp"
#include "src/data/datautil.hpp"

using std::mutex;
using std::set;
using std::shared_ptr;

namespace sv {

namespace data {
class AnalogSignal;
}

namespace devices {
class BaseDevice;
}

namespace channels {

class MultiplySSChannel : public UserChannel
{
	Q_OBJECT

public:
	MultiplySSChannel(
		data::Quantity quantity,
		set<data::QuantityFlag> quantity_flags,
		data::Unit unit,
		shared_ptr<data::AnalogSignal> signal1,
		shared_ptr<data::AnalogSignal> signal2,
		shared_ptr<devices::BaseDevice> parent_device,
		set<QString> channel_group_names,
		QString channel_name,
		double channel_start_timestamp);

private:
	shared_ptr<data::AnalogSignal> signal1_;
	shared_ptr<data::AnalogSignal> signal2_;
	size_t signal1_pos_;
	size_t signal2_pos_;
	mutex sample_append_mutex_;

private Q_SLOTS:
	void on_sample_appended();

};

} // namespace channels
} // namespace sv

#endif // CHANNELS_MULTIPLYSSCHANNEL_HPP
