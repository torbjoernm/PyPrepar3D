/*
 * dispatch_listener.hpp
 *
 *  Created on: Oct 24, 2014
 *      Author: Erik Tuerke
 */

#ifndef __PREPAR3D_SIMCONNECT_DISPATCH_LISTENER_HPP_
#define __PREPAR3D_SIMCONNECT_DISPATCH_LISTENER_HPP_

#include "common.hpp"
#include <vector>
#include <map>

namespace prepar3d
{
namespace simconnect
{
class DispatchListener
{
public:
	typedef std::vector<object> EventIDCallbackType;
	typedef std::map<SIMCONNECT_RECV_ID, EventIDCallbackType> SystemEventMapType;

	DispatchListener(PyObject *handle);

	void subscribe(const SIMCONNECT_RECV_ID &id, object callable);
	HRESULT DispatchListener::subscribeSystemEvent(const char *eventName, const SIMCONNECT_RECV_ID &recvID, object callable);

	void listen(const float &frequency);

	SystemEventMapType systemEventMap;

private:
	PyObject *_handle;

};

} // end namespace simconnect
} // end namespace prepar3d

#endif /* __PREPAR3D_SIMCONNECT_DISPATCH_LISTENER_HPP_ */
