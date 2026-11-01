/******************************Module*Header*******************************\
* Module Name: BDD_ErrorLog.hxx
*
* Basic Display Driver Logging Macros
*
*
* Copyright (c) 2010 Microsoft Corporation
*
\**************************************************************************/
#ifndef _BDD_ERRORLOG_HXX_
#define _BDD_ERRORLOG_HXX_

//
// Debug output is disabled unless BDD_ENABLE_LOGGING is set to 1 (e.g. /D BDD_ENABLE_LOGGING=1).
// When disabled the arguments are still compiled, but no code is generated.
//

#ifndef BDD_ENABLE_LOGGING
#define BDD_ENABLE_LOGGING 0
#endif

#if BDD_ENABLE_LOGGING
#define BDD_DBGPRINT(...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__)
#else
#define BDD_DBGPRINT(...) do { if (false) { DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__); } } while (false)
#endif

#define BDD_LOG_ERROR0(Msg) BDD_DBGPRINT("SampleDisplay: " Msg "\n")
#define BDD_LOG_ERROR1(Msg,Param1) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1)
#define BDD_LOG_ERROR2(Msg,Param1,Param2) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2)
#define BDD_LOG_ERROR3(Msg,Param1,Param2,Param3) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3)
#define BDD_LOG_ERROR4(Msg,Param1,Param2,Param3,Param4) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4)
#define BDD_LOG_ERROR5(Msg,Param1,Param2,Param3,Param4,Param5) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4, Param5)

//
// Warnings
//

#define BDD_LOG_WARNING0(Msg) BDD_DBGPRINT("SampleDisplay: " Msg "\n")
#define BDD_LOG_WARNING1(Msg,Param1) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1)
#define BDD_LOG_WARNING2(Msg,Param1,Param2) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2)
#define BDD_LOG_WARNING3(Msg,Param1,Param2,Param3) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3)
#define BDD_LOG_WARNING4(Msg,Param1,Param2,Param3,Param4) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4)
#define BDD_LOG_WARNING5(Msg,Param1,Param2,Param3,Param4,Param5) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4, Param5)

//
// Events (i.e. low-frequency tracing)
//

#define BDD_LOG_EVENT0(Msg) BDD_DBGPRINT("SampleDisplay: " Msg "\n")
#define BDD_LOG_EVENT1(Msg,Param1) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1)
#define BDD_LOG_EVENT2(Msg,Param1,Param2) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2)
#define BDD_LOG_EVENT3(Msg,Param1,Param2,Param3) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3)
#define BDD_LOG_EVENT4(Msg,Param1,Param2,Param3,Param4) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4)
#define BDD_LOG_EVENT5(Msg,Param1,Param2,Param3,Param4,Param5) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4, Param5)

//
// Information (i.e. high-frequency tracing)
//

#define BDD_LOG_INFORMATION0(Msg) BDD_DBGPRINT("SampleDisplay: " Msg "\n")
#define BDD_LOG_INFORMATION1(Msg,Param1) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1)
#define BDD_LOG_INFORMATION2(Msg,Param1,Param2) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2)
#define BDD_LOG_INFORMATION3(Msg,Param1,Param2,Param3) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3)
#define BDD_LOG_INFORMATION4(Msg,Param1,Param2,Param3,Param4) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4)
#define BDD_LOG_INFORMATION5(Msg,Param1,Param2,Param3,Param4,Param5) BDD_DBGPRINT("SampleDisplay: " Msg "\n", Param1, Param2, Param3, Param4, Param5)

//
// Function entry/exit tracing. Declare BDD_TRACE_FUNCTION() at the top of a function;
// the destructor logs the exit on every return path.
//

#if BDD_ENABLE_LOGGING

#define BDD_LOG_TRACE_ENTER(Func) BDD_DBGPRINT("SampleDisplay: --> %s\n", Func)
#define BDD_LOG_TRACE_LEAVE(Func) BDD_DBGPRINT("SampleDisplay: <-- %s\n", Func)

class BDD_FUNCTION_TRACER
{
public:
    explicit BDD_FUNCTION_TRACER(_In_z_ const char* pFunctionName) : m_pFunctionName(pFunctionName)
    {
        BDD_LOG_TRACE_ENTER(m_pFunctionName);
    }

    ~BDD_FUNCTION_TRACER()
    {
        BDD_LOG_TRACE_LEAVE(m_pFunctionName);
    }

private:
    const char* m_pFunctionName;
};

#define BDD_TRACE_FUNCTION() BDD_FUNCTION_TRACER BddFunctionTracer(__FUNCTION__)

#else

#define BDD_TRACE_FUNCTION()

#endif

//
// Low resource logging macros.
//

#define BDD_LOG_LOW_RESOURCE0(Msg)
#define BDD_LOG_LOW_RESOURCE1(Msg,Param1)
#define BDD_LOG_LOW_RESOURCE2(Msg,Param1,Param2)
#define BDD_LOG_LOW_RESOURCE3(Msg,Param1,Param2,Param3)
#define BDD_LOG_LOW_RESOURCE4(Msg,Param1,Param2,Param3,Param4)
#define BDD_LOG_LOW_RESOURCE5(Msg,Param1,Param2,Param3,Param4,Param5)

//
// Assertion logging macros.
//

#define BDD_LOG_ASSERTION0(Msg) NT_ASSERT(FALSE)
#define BDD_LOG_ASSERTION1(Msg,Param1) NT_ASSERT(FALSE)
#define BDD_LOG_ASSERTION2(Msg,Param1,Param2) NT_ASSERT(FALSE)
#define BDD_LOG_ASSERTION3(Msg,Param1,Param2,Param3) NT_ASSERT(FALSE)
#define BDD_LOG_ASSERTION4(Msg,Param1,Param2,Param3,Param4) NT_ASSERT(FALSE)
#define BDD_LOG_ASSERTION5(Msg,Param1,Param2,Param3,Param4,Param5) NT_ASSERT(FALSE)
#define BDD_ASSERT(exp) {if (!(exp)) {BDD_LOG_ASSERTION0(#exp);}}

#if DBG
#define BDD_ASSERT_CHK(exp) BDD_ASSERT(exp)
#else
#define BDD_ASSERT_CHK(exp) {}
#endif


#endif  //_BDD_ERRORLOG_HXX_

