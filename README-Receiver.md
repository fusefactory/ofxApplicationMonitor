# Application Monitor Receiver

Application monitor is a processing/java software to manage and control another application. It is very useful to check that the application is working, restart the application in case of crash or crash. 

The comunication beetween **ApplicationMonitor** and the other application works via OSC messages.

It was tested only for processing application, but should be compatible with all kind of application with few changes.

## OSC protocol

```/pid [pid-value-string]```

## ApplicationMonitorExampleClient

This is an example on how you have to implement the communication.

## Config

`application` 
- `name` name of the application to monitor.

- `path` folder path of the application to monitor.

`time` 

- `waitingStart`  time in **seconds** of the application to monitor. For example if the application needs 30 second to start up, startTime should be major of 30 with a little of margin, 45 for example.

- `pid` time to wait in **seconds** before restart the application. If the monitor doesn't receave /pid osc after this time it restart the application.

`port` 
- `inPort` osc input port
