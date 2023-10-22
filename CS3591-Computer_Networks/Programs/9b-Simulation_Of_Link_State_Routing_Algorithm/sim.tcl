# Create a simulator object
set ns [new Simulator]
set nr [open link.tr w]
$ns trace-all $nr
set nf [open link.nam w]
$ns namtrace-all $nf

# Define a 'finish' procedure
proc finish {} {
    global ns nr nf
    $ns flush-trace
    close $nf
    close $nr
    exec nam link.nam &
    exit 0
}

# Create nodes
for {set i 0} {$i < 12} {incr i} {
    set n($i) [$ns node]
}

# Create links
for {set i 0} {$i < 8} {incr i} {
    $ns duplex-link $n($i) $n([expr $i+1]) 1Mb 10ms DropTail
}
$ns duplex-link $n(0) $n(8) 1Mb 10ms DropTail
$ns duplex-link $n(1) $n(10) 1Mb 10ms DropTail
$ns duplex-link $n(0) $n(9) 1Mb 10ms DropTail
$ns duplex-link $n(9) $n(11) 1Mb 10ms DropTail
$ns duplex-link $n(10) $n(11) 1Mb 10ms DropTail
$ns duplex-link $n(11) $n(5) 1Mb 10ms DropTail

# Set up UDP agents and traffic
set udp0 [new Agent/UDP]
$ns attach-agent $n(0) $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0
set null0 [new Agent/Null]
$ns attach-agent $n(5) $null0
$ns connect $udp0 $null0

set udp1 [new Agent/UDP]
$ns attach-agent $n(1) $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005
$cbr1 attach-agent $udp1
$ns attach-agent $n(5) $null0 ;# Reused "null0" agent
$ns connect $udp1 $null0

# Configure routing
$ns rtproto LS
$ns rtmodel-at 10.0 down $n(11) $n(5)
$ns rtmodel-at 15.0 down $n(7) $n(6)
$ns rtmodel-at 30.0 up $n(11) $n(5)
$ns rtmodel-at 20.0 up $n(7) $n(6)

# Set flow identifiers
$udp0 set fid_ 1
$udp1 set fid_ 2

# Set colors for data flows
$ns color 1 Red
$ns color 2 Green

# Schedule events to start traffic sources
$ns at 1.0 "$cbr0 start"
$ns at 2.0 "$cbr1 start"

# Finish the simulation
$ns at 45 "finish"
$ns run
