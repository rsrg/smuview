/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2017 Frank Stettner <frank-stettner@gmx.net>
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

#ifndef VIEWS_SINKCONTROLVIEW_HPP
#define VIEWS_SINKCONTROLVIEW_HPP

#include <memory>

#include <QComboBox>

#include "src/views/baseview.hpp"

using std::shared_ptr;

namespace sv {

class Session;

namespace devices {
class HardwareDevice;
}

namespace widgets {
class ControlButton;
class Led;
class OptionalValueControl;
class ValueControl;
}

namespace views {

class SinkControlView : public BaseView
{
	Q_OBJECT

public:
	SinkControlView(Session& session,
		shared_ptr<devices::HardwareDevice> device,
		QWidget* parent = nullptr);

private:
	shared_ptr<devices::HardwareDevice> device_;

	widgets::Led *ccLed;
	widgets::Led *cvLed;
	widgets::Led *ovpLed;
	widgets::Led *ocpLed;
	widgets::Led *otpLed;
	widgets::Led *uvcLed;
	widgets::ControlButton *enableButton;
	QComboBox *regulationBox;
	QString regulation;
	widgets::ValueControl *setValueControl;

	widgets::OptionalValueControl *ovpControl;
	widgets::OptionalValueControl *ocpControl;
	widgets::OptionalValueControl *uvcControl;

	void setup_ui();
	void connect_signals();
	void init_values();

protected:

public Q_SLOTS:

private Q_SLOTS:
	void on_enabled_changed(const bool enabled);
	void on_value_changed(const double value);
	void on_ovp_enabled_changed(const bool enabled);
	void on_ovp_threshold_changed(const double value);
	void on_ocp_enabled_changed(const bool enabled);
	void on_ocp_threshold_changed(const double value);
	void on_uvc_enabled_changed(const bool enabled);
	void on_uvc_threshold_changed(const double value);

};

} // namespace views
} // namespace sv

#endif // VIEWS_SINKCONTROLVIEW_HPP
