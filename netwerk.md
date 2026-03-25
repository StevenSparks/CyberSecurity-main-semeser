@startuml


nwdiag {
    network vCenter {
        address = "192.168.151.0/24"
        pfsense1 [address = "192.168.151.185"];
    }
    network vlanA {
        pfsense1 [address = "172.16.1.1/24"];
        Pfsense2 [address = "172.16.1.2/24"];
        serverA 
        workstationA 
    }
    network vlanB {
        Pfsense2 [address = "172.16.2.1/24"];
        serverB 
        workstationB 
        Database1
    }
}



@enduml 