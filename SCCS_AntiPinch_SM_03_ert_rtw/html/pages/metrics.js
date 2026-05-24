function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["SCCS_AntiPinch_SM_03.c:SCCS_AntiPinch_SM_03_M_"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	size: 8};
	 this.metricsArray.var["SCCS_AntiPinch_SM_03_DW"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	size: 3};
	 this.metricsArray.var["SCCS_AntiPinch_SM_03_U"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	size: 32};
	 this.metricsArray.var["SCCS_AntiPinch_SM_03_Y"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	size: 24};
	 this.metricsArray.fcn["SCCS_AntiPinch_SM_03_initialize"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["SCCS_AntiPinch_SM_03_step"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["SCCS_AntiPinch_SM_03_terminate"] = {file: "C:\\Users\\Kishore\\Desktop\\Smart_Closure_Control_System\\SCCS_AntiPinch_SM_03_ert_rtw\\SCCS_AntiPinch_SM_03.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'SCCS_AntiPinch_SM_03_metrics\'});">Global Memory: 67(bytes) Maximum Stack: 0(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
