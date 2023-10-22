# Create a new simulator
set ns [new Simulator]

# Trace packets on all links
set nf [open out.nam w]
$ns trace-all $nf
$ns namtrace-all $nf

# Create nodes
set n0 [$ns node]
set n1 [$ns node]

# Create a link between nodes with specified bandwidth, delay, and queue type
$ns duplex-link $n0 $n1 1Mb 10ms RED

# Creating a larger topology
for {set i 0} {$i < 7} {incr i} {
    set n($i) [$ns node]
}
for {set i 0} {$i < 7} {incr i} {
    $ns duplex-link $n($i) $n([expr ($i+1)%7]) 1Mb 10ms RED
}

# Link failures
$ns rtmodel-at <time> up $n0 $n1
# You can specify a time for the link to go down by changing 'up' to 'down'

# Creating UDP connection
set udp [new Agent/UDP]
set null [new Agent/Null]
$ns attach-agent $n0 $udp
$ns attach-agent $n1 $null
$ns connect $udp $null

# Creating Traffic (On Top of UDP)
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 0.005
$cbr attach-agent $udp

# Post-Processing Procedures
proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exec nam out.nam &
    exit 0
}

# Schedule Events
$ns at 5.0 "finish"

# Run the simulation
$ns run
