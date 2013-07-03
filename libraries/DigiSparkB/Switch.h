class ISwitch {
public:
  virtual boolean Toggle() = 0;
  virtual boolean Set() = 0;
  virtual boolean Reset() = 0;
  virtual boolean GetState() = 0;
};

class Switch : ISwitch{
private:
  boolean m_state;
  DigiSparkB::ePins m_pin;
public:
  Switch(DigiSparkB::ePins pin) {
    m_pin = pin;
    m_state = digitalRead(m_pin);
  }
  Switch(DigiSparkB::ePins pin, boolean state) {
    m_state = state;
    m_pin = pin;
    digitalWrite(m_pin, m_state);
  }
  
  boolean Toggle() { 
    m_state = !m_state; 
    digitalWrite(m_pin, m_state);
    return m_state;
  }
  boolean Set()  {
    m_state = true; 
    digitalWrite(m_pin, m_state);
    return m_state;
  }
  boolean Reset()  {
    m_state = false; 
    digitalWrite(m_pin, m_state);
    return m_state;
  }
  
  boolean GetState() {
    return m_state;
  }
};

class SwitchMemory : ISwitch {
private:
  Switch* m_sw;
  boolean m_prevState;
public:
  SwitchMemory(DigiSparkB::ePins pin) {
    m_sw = new Switch(pin);
    m_prevState = m_sw->GetState();
  }
  SwitchMemory(DigiSparkB::ePins pin, boolean state) {
    m_sw = new Switch(pin, state);
    m_prevState = m_sw->GetState();
  }
  SwitchMemory(Switch* sw) {
    m_sw = sw;
    m_prevState = m_sw->GetState();
  }
  boolean Toggle() {
    m_prevState = m_sw->GetState();
    return m_sw->Toggle();
  }
  boolean Set() {
    m_prevState = m_sw->GetState();
    return m_sw->Set();
  }
  boolean Reset() {
    m_prevState = m_sw->GetState();
    return m_sw->Reset();
  }
  boolean GetState() {
    return m_sw->GetState();
  }
  boolean WasToggled() {
    boolean retVal = m_prevState != m_sw->GetState();
    m_prevState = m_sw->GetState();
    m_sw->GetState();
    return retVal;
  }
};

