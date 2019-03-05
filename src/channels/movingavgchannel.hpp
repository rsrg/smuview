/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2019 Frank Stettner <frank-stettner@gmx.net>
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

#ifndef CHANNELS_MOVINGACGCHANNEL_HPP
#define CHANNELS_MOVINGACGCHANNEL_HPP

#include <memory>
#include <set>

#include <QObject>

#include "src/channels/basechannel.hpp"
#include "src/channels/userchannel.hpp"
#include "src/data/datautil.hpp"

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

class MovingAvgChannel : public UserChannel
{
	Q_OBJECT

public:
	MovingAvgChannel(
		data::Quantity quantity,
		set<data::QuantityFlag> quantity_flags,
		data::Unit unit,
		shared_ptr<data::AnalogSignal> signal,
		uint avg_sample_count,
		shared_ptr<devices::BaseDevice> parent_device,
		set<QString> channel_group_names,
		QString channel_name,
		double channel_start_timestamp);

private:
	shared_ptr<data::AnalogSignal> signal_;
	uint avg_sample_count_;
	vector<double> avg_samples_;
	size_t next_signal_pos_;

private Q_SLOTS:
	void on_sample_appended();

};

} // namespace channels
} // namespace sv

#endif // CHANNELS_MOVINGACGCHANNEL_HPP
