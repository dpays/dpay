<p align="center">
  <img src="https://github.com/dpays/dpay-desktop/raw/master/icon.png" alt="dPay API Portal" width="100">
  <br>
  <br>
</p>

# dPay (0.20.2-stable)

**Decentralized MultiChain Smart Network (DMSN) (Stable Release)**

dPay is a Delegated Proof of Stake blockchain that uses a "Proof of Brain" social consensus algorithm for token allocation.

## dPay Documentation / Resources
- [dPay Resource Requirements ](https://github.com/dpays/dpay/blob/stable/doc/resource-requirements.md)
- [dPay Git Guidelines](https://github.com/dpays/dpay/blob/stable/doc/git-guidelines.md)
- [Exchange Documentation](#)
  - [Building dPay From Source For Exchanges](https://github.com/dpays/dpay/blob/stable/doc/)
  - [Building dPay With Docker For Exchanges](https://github.com/dpays/dpay/blob/stable/doc/)
- [Installation Documentation](#)
  - [dPay Live Network](#)
    - [Build Custom Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/live/build-from-source.md)
    - [Build Custom Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/live/docker.md)
  - [Franklin Test Network](#)
    - [Build Franklin From Source](https://github.com/dpays/dpay/blob/stable/doc/install/live/build-from-source.md)
    - [Build Franklin With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/franklin/docker.md)
    - [Franklin Seed Nodes](https://github.com/dpays/dpay/blob/stable/doc/install/franklin/seed-nodes.md)
  - [Jackson Test Network](#)
    - [Build Jackson From Source](https://github.com/dpays/dpay/blob/stable/doc/install/jackson/build-from-source.md)
    - [Build Jackson With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/jackson/docker.md)
    - [Jackson Seed Nodes](https://github.com/dpays/dpay/blob/stable/doc/install/jackson/seed-nodes.md)
  - [Jefferson Dev Network](#)
    - [Build Jefferson From Source](https://github.com/dpays/dpay/blob/stable/doc/install/jefferson/build-from-source.md)
    - [Build Jefferson With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/jefferson/docker.md)
    - [Jefferson Seed Nodes](https://github.com/dpays/dpay/blob/stable/doc/install/jefferson/seed-nodes.md)  
  - [Kennedy Test Network](#)
    - [Build Kennedy From Source](https://github.com/dpays/dpay/blob/stable/doc/install/kennedy/build-from-source.md)
    - [Build Kennedy With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/kennedy/docker.md)
    - [Kennedy Seed Nodes](https://github.com/dpays/dpay/blob/stable/doc/install/kennedy/seed-nodes.md)
  - [Custom Network](#)
    - [Creating A dPay SideChain](https://github.com/dpays/dpay/blob/stable/doc/install/custom-network/creating-a-dpay-sidechain.md)
    - [Build Custom Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/custom-network/build-from-source.md)
    - [Build Custom Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/custom-network/docker.md)
- [dPay Developer Documentation](https://developers.dpays.io/)
  - [dPay Developer Documentation](https://developers.dpays.io/)
  - [dPay API Documentation](https://developers.dpays.io/apidefinitions/)
  - [dPayID Documentation](https://developers.dpays.io/services/#services-dpayid)
  - [Jefferson RPC/WS Proxy Server](https://developers.dpays.io/services/#services-jefferson)
  - [dPay Data Service](https://developers.dpays.io/services/#DPDS)
  - [dPayJS Documentation](https://library.dpays.io/dpayjs)
  - [dPayTS Documentation](https://library.dpays.io/dpayts)
  - [dPay RPC/WS API Notes](https://github.com/dpays/dpay/blob/stable/doc/api-notes.md)
  - [dPay Plugin Documentation](https://github.com/dpays/dpay/blob/stable/doc/plugin.md)
  - [dPay SQRT Documentation](https://github.com/dpays/dpay/blob/stable/doc/sqrt.md)
  - [dPay-Core Testing Guide](https://github.com/dpays/dpay/blob/stable/doc/testing.md)
  - [dPay Debug Node Documentation](https://github.com/dpays/dpay/blob/stable/doc/dpay-debug-node.md)
- [dPay Witness Documentation](#)
  - [Witness Node Installation](https://github.com/dpays/dpay/blob/stable/doc/witness/installation.md)
  - [Voting For Witnesses](https://github.com/dpays/dpay/blob/stable/doc/voting-for-witnesses.md) - Coming Soon
- [dPay Network Information](#)
  - [Build Variables](https://github.com/dpays/dpay/blob/stable/doc/networks/build-variables.md)
  - [dPay Network Ports](https://github.com/dpays/dpay/blob/stable/doc/dpay-network-ports.md)
- [dPay Network Information](#)
  - [Build Variables](https://github.com/dpays/dpay/blob/stable/doc/networks/build-variables.md)
  - [dPay Network Ports](https://github.com/dpays/dpay/blob/stable/doc/dpay-network-ports.md)


## dPay LiveNet Details
- Stable Version is 0.19.6
- Newest Version is 0.20.0
- Chain was officially started by 21 community members who formed a governance on Sep, 11 2018 07:31:16
- Currency symbol BEX, short for BenchMark, a private issued currency using the name of an old and out-of-circulation legal [Germany currency]()
- Produces 10,512,000 blocks per year.
- Produces 28,800 blocks per day.
- 10% APR inflation narrowing to 1% APR over 20 years.
- 75% of inflation to "Proof of Brain" social consensus algorithm.
- 15% of inflation to stake holders.
- 10% of inflation to block producers.
- Dollar-backed currency (BBD) that can be VESTED on-chain.
- Built-in decentralized exchange for BEX and BBD.
- **POW mining is disabled.** and chain is now 100% DPOS.


##  Quick Installation

  ```
  docker run \
      -d -p 6620:6620 -p 1776:1776 --name dpayd-default \
      --restart unless-stopped dpay/dpay
  ```

## dPay Built-in Networks (Live/Test/Dev)

### dPay Live/Public Network
- [Installing dPay Live/Public Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/live/build-from-source.md)
- [Installing dPay Live/Public Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/live/docker.md)
- [Seed Nodes For Live/Public Network](https://github.com/dpays/dpay/blob/stable/doc/install/live/seed-nodes.md)
- Currency symbol BEX.
- 10% APR inflation narrowing to 1% APR over 20 years.
- 75% of inflation to "Proof of Brain" social consensus algorithm.
- 15% of inflation to stake holders.
- 10% of inflation to block producers.

### dPay Jackson Test Network
- [Installing dPay Jackson Test Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/jackson/build-from-source.md)
- [Installing dPay Jackson Test Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/jackson/docker.md)
- [Seed Nodes For dPay Jackson Test Network](https://github.com/dpays/dpay/blob/stable/doc/install/jackson/seed-nodes.md)
- Currency symbol JACKS.
- 10% APR inflation narrowing to 1% APR over 20 years.
- 75% of inflation to "Proof of Brain" social consensus algorithm.
- 15% of inflation to stake holders.
- 10% of inflation to block producers.

### dPay Franklin Test Network
- [Installing dPay Franklin Test Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/franklin/build-from-source.md)
- [Installing dPay Kennedy Test Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/franklin/docker.md)
- [Seed Nodes For dPay Kennedy Test Network](https://github.com/dpays/dpay/blob/stable/doc/install/franklin/seed-nodes.md)
- Currency symbol FRANK.
- 10% APR inflation narrowing to 1% APR over 20 years.
- 75% of inflation to "Proof of Brain" social consensus algorithm.
- 15% of inflation to stake holders.
- 10% of inflation to block producers.

### dPay Kennedy Test Network
- [Installing dPay Kennedy Test Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/kennedy/build-from-source.md)
- [Installing dPay Kennedy Test Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/kennedy/docker.md)
- [Seed Nodes For dPay Kennedy Test Network](https://github.com/dpays/dpay/blob/stable/doc/install/kennedy/seed-nodes.md)
- Currency symbol KEN.
- 10% APR inflation narrowing to 1% APR over 20 years.
- 75% of inflation to "Proof of Brain" social consensus algorithm.
- 15% of inflation to stake holders.
- 10% of inflation to block producers.

### dPay Jefferson Dev Network
- [Installing dPay Jefferson Dev Network From Source](https://github.com/dpays/dpay/blob/stable/doc/install/jefferson/build-from-source.md)
- [Installing dPay Jefferson Dev Network With Docker](https://github.com/dpays/dpay/blob/stable/doc/install/jefferson/docker.md)
- [Seed Nodes For dPay Jefferson Dev Network](https://github.com/dpays/dpay/blob/stable/doc/install/jefferson/seed-nodes.md)
- Currency symbol FREE.
- 10% APR inflation narrowing to 1% APR over 20 years.
- 75% of inflation to "Proof of Brain" social consensus algorithm.
- 15% of inflation to stake holders.
- 10% of inflation to block producers.


# NO SUPPORT & NO WARRANTY
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# DISCLAIMER FOR THE ISSUANCE OF PRIVATE CURRENCY
THE DIGITAL CURRENCIES CREATED BY, MANAGED BY, DISTRIBUTED BY, STORED BY AND INFLATED BY DPAY, A PEER-TO-PEER "BLOCKCHAIN" SOFTWARE, ARE CURRENCY. `BEX` (BENCHMARKS), `BBD` (BENCHMARK-BACKED DOLLARS), `BP` (BENCHMARK POWER), `VESTS` AND OTHER DIGITAL CURRENCIES ON THE DPAY SYSTEM WILL NEVER BE SOLD BY THE DEVELOPERS OF THIS SOFTWARE. THE `BEX` AND ALL OTHER PRIVATE CURRENCIES FOUND WITHIN THE DPAY ECOSYSTEM OR CONNECTED TO THE DPAY ECOSYSTEM CAN ONLY BE EARNED THROUGH VARIOUS FORMS OF MINING, INCLUDING DATA MINING THROUGH DECENTRALIZED APPLICATIONS, WHERE USERS ARE PAID FOR THEIR DATA OR BY THE MEANS OF TRADITIONAL "PROOF-OF-WORK" MINING, WHERE A COMPUTER IS PAID IN DPAY'S NATIVE CURRENCIES, IN EXCHANGE FOR A USER'S COMPUTER POWER, IN ORDER TO VERIFY TRANSACTIONS ON THE NETWORK.

WHILE `BEX`, `BBD` AND OTHER CURRENCIES ISSUED BY COMMUNITY MEMBERS, OUTSIDE DEVELOPERS OR COMPANIES WHO CHOOSE TO USE THE DPAY SOFTWARE AND IN SOME CASES, TOTALLY SEPARATE FROM THE DPAY ECOSYSTEM ITSELF, MAY MAKE CURRENCIES LIKE `BEX` AND `BBD` AVAILABLE ON CRYPTOCURRENCY EXCHANGES. BY USING THIS SOFTWARE, EARNING `BEX` OR ANOTHER DPAY-RELATED DIGITAL CURRENCIES OR PURCHASING `BEX` FROM A COMMUNITY MEMBER WHO HAS LEGALLY AND RIGHTFULLY EARNED `BEX` OR ANOTHER DPAY-RELATED DIGITAL CURRENCY, YOU AGREE THAT YOU SHALL NOT HOLD THE DEVELOPERS LIABLE FOR THE ACTIONS TAKEN BY HOLDERS OF `BEX` OR ANOTHER DPAY-RELATED DIGITAL CURRENCY. BY USING THE DPAY SOFTWARE, PURCHASING ANY DPAY-RELATED DIGITAL CURRENCY FROM A HOLDER VIA ANY MEANS OF EXCHANGE, INCLUDING BUT NOT LIMITED TO A CRYPTOCURRENCY EXCHANGE, A DECENTRALIZED CRYPTOCURRENCY EXCHANGE, IN-PERSON EXCHANGE OR ANY OTHER MEANS OF EXCHANGE WHERE YOU ARE ACQUIRING THE OWNERSHIP OF `BEX` OR ANOTHER DPAY-RELATED DIGITAL CURRENCY, YOU AGREE THAT `DISTRIBUTED WEBS PROJECT, LLC.` AND ITS DEVELOPERS HAVE NO CONTROL OVER WHAT HAPPENS ON THE DPAY NETWORK. YOU AGREE THAT `DISTRIBUTED WEBS PROJECT, LLC.` AND ITS DEVELOPERS, WHILE MAINTAINING THE SOFTWARE FOR THE COMMUNITY, DOES NOT HAVE A LIFELONG CONTRACT FOR DEVELOPING THE DPAY SOFTWARE AND YOU AGREE THAT YOU UNDERSTAND HOW A CONSENSUS WORKS AND YOU AGREE THAT YOU UNDERSTAND THE PROCESS BEHIND WHICH COMMUNITY MEMBERS AND NETWORK WITNESSES VOTED IN BY MEMBERS OF VARIOUS DPAY-BASED COMMUNITIES COULD ISSUE A NETWORK PROPOSAL AND SUCCESSFULLY REMOVE `DISTRIBUTED WEBS PROJECT, LLC.` AS LEAD DEVELOPERS AND MAINTAINERS OF THE ENTIRE DPAY SOFTWARE COLLECTION. BY DOWNLOADING, USING IN ANY CAPACITY, INCLUDING BUT NOT LIMITED TO DPAY'S WALLET SOFTWARE, DBROWSER'S WEB BROWSER, DWEB'S INTERNET PROTOCOL AND/OR OTHER SOFTWARE DIRECTLY RELATED TO DPAY, YOU HEREBY AGREE AND ACCEPT DPAY'S **"`DISCLAIMER FOR THE ISSUANCE OF PRIVATE CURRENCY`"** AND FORFEIT ALL RIGHTS TO PROSECUTE OR SEEK ANY LEGAL REMEDY BASED AROUND THE USAGE OF THE DPAY SOFTWARE OR ANY CURRENT, PENDING OR FUTURE ACQUISITION OR EARNINGS OF ANY DPAY-RELATED DIGITAL CURRENCY. BY BUYING, SELLING, EXCHANGING, SPENDING, BARTERING, PROFITING, LOSING,  DESTROYING, INVESTIGATING OR ATTEMPTING TO INQUIRE ABOUT `BEX`, `BBD`, `BP`,  `VEST` OR ANY OTHER DPAY-RELATED DIGITAL CURRENCIES, YOU AGREE `BEX` AND  `BBD` ARE PRIVATE CURRENCIES AND NOT SECURITIES. YOU ALSO AGREE THAT YOU UNDERSTAND AND AGREE THAT `BEX` AND OTHER DPAY-RELATED CRYPTOCURRENCIES AND DIGITAL CURRENCIES ARE CURRENCIES AND NOT SECURITIES.

# DISCLAIMER FOR STATEMENTS
`DISTRIBUTED WEBS PROJECT, LLC.` AND ITS DEVELOPERS MAY END UP COMING UP WITH IDEAS OR ENVISIONING PLANS, IN THE PROCESS OF DEVELOPING THE DPAY SOFTWARE COLLECTION. BY USING AND/OR READING ANY DPAY-BASED SOFTWARE, WEBSITE, WHITEPAPER, TELEGRAM POST, CHAT MESSAGE, PRESS RELEASE, TWEET, FACEBOOK POST, SOCIAL MEDIA POSTING, META DESCRIPTION, SOFTWARE REPOSITORY DOCUMENTATION, DEVELOPER DOCUMENTATION, SOFTWARE-BASED DOCUMENTATION, SOFTWARE LICENSING AGREEMENT, IMAGES, VIDEOS, INTERVIEWS OR ANYTHING THAT CAN BE ATTRIBUTED TO A STATEMENT MADE BY `DISTRIBUTED WEBS PROJECT, LLC.`, YOU AGREE AND UNDERSTAND THAT THE STATEMENTS MADE ON ANY WEBSITE, WHITEPAPER, PRESS RELEASE, TWEET, FACEBOOK POST, SOCIAL MEDIA POSTING, TELEGRAM POST, CHAT MESSAGE, META DESCRIPTION, SOFTWARE REPOSITORY DOCUMENTATION, DEVELOPER DOCUMENTATION, SOFTWARE-BASED DOCUMENTATION, SOFTWARE LICENSING AGREEMENT, IMAGES, VIDEOS, INTERVIEWS OR ANYTHING THAT CAN BE ATTRIBUTED TO A STATEMENT MADE BY `DISTRIBUTED WEBS PROJECT, LLC.` AND/OR ANY OF ITS DEVELOPERS OR AFFILIATES ARE SIMPLY VISIONS AND ARE NOT GUARANTEED TO COME TO FRUITION OR EXIST IN ANY CAPACITY WHETHER AT THIS PRESENT TIME OR AT ANY TIME IN THE FUTURE.

# SOFTWARE DEVELOPMENT DISCLAIMER
`DISTRIBUTED WEBS PROJECT, LLC.`, IS A SOFTWARE COMPANY AND IS PRODUCING THE `DPAY` SOFTWARE AS FREE, OPEN SOURCE SOFTWARE. THIS SOFTWARE MAY ENABLE THOSE WHO DEPLOY IT TO LAUNCH A BLOCKCHAIN OR DECENTRALIZED APPLICATIONS WITH THE FEATURES DESCRIBED ABOVE. `DISTRIBUTED WEBS PROJECT, LLC.` WILL NOT BE LAUNCHING A PUBLIC BLOCKCHAIN BASED ON THE `DPAY` SOFTWARE. IT WILL BE THE SOLE RESPONSIBILITY OF THIRD PARTIES AND THE COMMUNITY AND THOSE WHO WISH TO GROW THE `DPAY` ECOSYSTEM TO IMPLEMENT THE FEATURES AND/OR PROVIDE THE SERVICES DESCRIBED ABOVE AS THEY SEE FIT. `DISTRIBUTED WEBS PROJECT, LLC.` DOES NOT GUARANTEE THAT ANYONE WILL IMPLEMENT SUCH FEATURES OR PROVIDE SUCH SERVICES OR THAT THE `DPAY` SOFTWARE WILL BE ADOPTED AND DEPLOYED IN ANY WAY.
