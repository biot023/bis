Feature: Generating a bit instruction set exec

  So that:   I can generate runnable instruction sets from vectors of integers
  As a:      Biot of some kind
  I want to: Give const access to my genome and have an instruction set exec generated from it

  Scenario: Generating a bis exec and casually inspecting the instruction set
    Given I have an output directory "generate_and_casual_inspection"
    And I have a biot with a random genome 10000 integers long
    And my biot has an action count of 10
    And I have a sensory array with senses with the following index counts:
      | Index Count |
      |        1296 |
      |          36 |
      |           4 |
    And I have the following bis config attributes object:
      | Attribute            | Value |
      | memory_size          |    32 |
      | max_function_offset  |    24 |
      | end_function_ratio_a |     1 |
      | end_function_ratio_b |     2 |
    And I generate a bis exec with the biot and config attributes
    Then an instruction set should have been generated for my biot
    When I inspect the generated exec
    Then it should contain between 9550 and 9900 individual instructions
    And it should contain between 850 and 940 sequences of instructions
    When I inspect the exec's generated code
    Then the code should have at least 500 functions
    And the code should have many newlines
    And the code should have indentation
    And the code should have the following strings at counts of 300 to 450
      | String             |
      | PushAction         |
      | PopAction          |
      | ClearActions       |
      | PushParameter      |
      | PopParameter       |
      | ClearParameters    |
      | SetMemoryIndex     |
      | OffsetMemoryIndex  |
      | WriteConst         |
      | WriteConstAtIndex  |
      | WriteConstAtOffset |
      | WriteSense         |
      | WriteSenseAtIndex  |
      | WriteSenseAtOffset |
      | Increment          |
      | IncrementAtIndex   |
      | IncrementAtOffset  |
      | Call               |
      | If                 |
      | While              |
    And the code should have the following strings at counts of 50 to 150
      | String      |
      | MemEqConst  |
      | MemLtConst  |
      | MemGtConst  |
      | MemEqIndex  |
      | MemLtIndex  |
      | MemGtIndex  |
      | MemEqOffset |
      | MemLtOffset |
      | MemGtOffset |
      | And         |
      | Or          |
      | Not         |
