// Setup all node parameters from a simple XML file.
// Load and save has meaning only on the master node
void HyNode::load(QString filename)
{
    QDomDocument do;
    if (!doc.setContent(filename)) return;

    // extract network identification

    // save content
}

//We collect and write out all known parameters to an XML file
//It includes the node-based parameters, embedding the configuration from the plugins 
// Load ans save has meaning only on the master node
void HyNode::save(QString filename)
{
}

// Backup current setup in a storage thus we have something we can fallback into
void HyNode::backup()
{}

// There could be a lot of changes done in the matrix that depends on each other
// In order to make sure that we are not creating an intermediate situation, a commit call should be made to roll out 
// the modifications over the whole matrix
void HyNode::commit()
{
}

//When there is a need to restore a previous version of matrix setup, this function is needed
//It rolls back to the last saved version of the settings and dispatches it to all connected nodes.
void HyNode::rollback()
{}

// sending out signal of what nodes and plugins should be updated
void HyNode::sendRefresh()
{
}

//Sending complete node definieiton
void HyNode::queryNodeInfoReply()
{}


// create an UDP server at the given port for listening incoming discovery request
// we use UDP only for discovery. Communication loads are done over TCP
void Hynode::setupBroadcastServer()
{
}

// we dispatch broadcast messages on different ports to locate available matrices
void HyNode::scanForMatrix()
{
}

// After we found out on which port the targeted matrix is, we setup the commuication server that would handle all matrix related
// communications. This server is responsible to maintain and rebuild the connection in somehow failsafe manner
// Communication server also enables base log functions for all part of the node
void HyNode::setupCommunicationServer()
{
}

// main entry point for the power and status level changes throughout the matrix
void HyNode::MatrixStatusChanged(int status)
{
}

// Loads a plugin into an empty slot and connects all communication interface.
void HyNode::loadPlugin(QString name, QDomNode node)
{
}

// Disconnect and drop plugin from the node. Might be manually requested or automatic (plugin is unresponsive, ex.)
void HyNode::discardPlugin(int serial)
{
} 

// Timestamp the logline with local information and sends it to the master node
void HyNode::log(QString str)
{
}

// Append necesseary information to the node and send to the master
// This might have some token ring approach later on to ensure that if master is failing there is a backup plan
// But for now we go for the simple master-servants setups
void HyNode::sendData(QDomNode node)
{
}

// Handling messages from the master node, this is the major message entry ponint for the nodes
void HyNode::receiveData(QDomNode node)
{
}

// We create a secured TCP link to the master node
void HyNode::connectToNode()
{
}

// We disconnect from the master node. Also, we tell it politely, why we are leaving the matrix
void HyNode::disconnectFromNode()
{
}

// If we found the matrix we want to join to, we need to create keypairs for this connection and send the public part
// directly to the master. This is done over UDP. After sending out the UDP package, we wit a bit for its processing, then we are 
// trying to connect to it using the privae key. The acceptance of the pub key depends on the master itself. It might not be accepted
// if the master is not in installation mode or there is another issue prevents receiving that. It might be a wise idea to encode this 
// package with the pub key of the master, but that implementation is not yet on the horizon.
void HyNode::registerNodeOnMatrix()
{
}

// Function that is executed when time info is arriving from the master node
// It changes the node's time if that is possible, or calculates offset that is used wherever date/time is needed.
void HyNode::timeSync() 
{
}

// Function executed 
void HyNode::ping()
{}
