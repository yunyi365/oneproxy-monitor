/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 * @FileName: monitormanager.h
 * @Description: TODO
 * All rights Reserved, Designed By huih
 * @Company: onexsoft
 * @Author: hui
 * @Version: V1.0
 * @Date: 2017年2月23日 下午12:57:44
 *  
 */

#ifndef MONITOR_MONITORMANAGER_H_
#define MONITOR_MONITORMANAGER_H_

#include "conf/config.h"
#include "capturedata.h"
#include "supermonitor.h"
#include "managerbase.h"
#include "pcap.h"
#include "parsedata.h"

class MonitorManager:public ManagerBase {
public:
	MonitorManager();
	virtual ~MonitorManager();

protected:
	virtual void start_child();
	static void handle_signal(int sig);
	static void monitorData(u_char *arg, const struct pcap_pkthdr *pkthdr, const u_char *packet);
	void stop_childThread();
public:
	ParseData* get_parseData(int port);
	int get_parseDataThreadSize();
private:
	CaptureData captureData;
//	SuperMonitor sm;
	std::vector<SuperMonitor*> m_superMonitorVec;
	std::vector<ParseData*> m_parseDataVec;
	static bool m_stop;
};

#endif /* MONITOR_MONITORMANAGER_H_ */
